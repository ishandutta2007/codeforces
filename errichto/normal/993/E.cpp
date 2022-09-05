#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <stack>
#include <iomanip>
#include <cmath>
#include <climits>
#include <complex>
#include <cmath>
#define M_PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070
#define fi first
#define se second
#define th second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef complex<double> cd;

const int maxN = 1.1e6 + 3, MOD = 1e9 + 7, LG = 20;
//NOTE: maxN>2^LG must be held, remember maxN is twice ur biggest polynom

cd ur[maxN], res[maxN], ors[maxN], cf[maxN];
//assumes sz and step are 2-powers
void FFT(int cfs, int step, int his, int rs, int sz, cd *res){
    if(cfs == 1)
        for(int i = 0; i < sz; i++) res[i] = cf[his];
    else{
        
        FFT(ceil(cfs/2.0), step+1, his, rs<<1, sz>>1, res);
        FFT(cfs>>1, step+1, 1 << step | his, rs<<1, sz>>1, res + (sz>>1));
        
        for(int i = 0, m = sz >> 1; i < m; i++){
            cd cr = res[i];
            res[i] = cr + res[i + m] * ur[i * rs];
            res[i + m] = cr + res[i + m] * ur[(i + m) * rs];
        }
    }
}

void mu(const vector<ll> &a, const vector<ll> &b, vector<ll> &ans){
    int sz = 1<<int(ceil(log2(a.size() + b.size() - 1)));
    
    for(int i = 0; i < a.size(); i++) cf[i] = a[i];
    FFT((int)a.size(), 0, 0, (1<<LG)/sz, sz, res);
    
    for(int i = 0; i < b.size(); i++) cf[i] = b[i];
    FFT((int)b.size(), 0, 0, (1<<LG)/sz, sz, ors);
    
    for(int i = 0; i < sz; i++) cf[i] = conj(res[i] * ors[i]);
    FFT(sz, 0, 0, (1<<LG)/sz, sz, res);
    
    for(int i = 0; i < a.size() + b.size() - 1; i++)
        ans.push_back(ll(round(res[i].real() / sz)));
    
}

vector<ll> getDiffer(const vector<ll> &vc){
    vector<ll> ret, rev = vc, res;
    
    int n = int(vc.size());
    
    reverse(rev.begin(), rev.end());
    for(int i = 0; i < n; i++)
        rev.push_back(0);
    
    //for(ll el: vc) cout << el << ' '; cout << '\n';
    //for(ll el: rev) cout << el << ' '; cout <<'\n';
    
    mu(rev, vc, res);
    //for(ll el: res) cout << el << ' '; cout <<'\n';
    
    res = vector<ll>(res.end() - n * 2, res.end());
    
    return res;
}

int n;

ll arr[maxN], x, answers[maxN];
vector<ll> enc;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ur[0] = 1, ur[1] = polar(1.0, M_PI * 2 / (1 << LG));
    
    for(int i = 2; i < (1 << LG); i++)
        ur[i] = polar(1.0, i * M_PI * 2 / (1 << LG));
    
    cin >> n >> x;
    
    arr[0] = 1;
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i] < x) arr[i] = 1;
        else arr[i] = 0;
    }
    
    for(int i = 0, j; i <= n; i = j){
        for(j = i + 1; j <= n && !arr[j]; j++);
        answers[0] += ll(j - i - 1) * (j - i) / 2;
        enc.push_back(j - i);
    }
    
    //for(ll el: enc) cout << el << ' '; cout <<'\n';
    
    vector<ll> difs = getDiffer(enc);
    
    for(int i = 1; i <= n && i < difs.size(); i++)
        answers[i] = difs[i];
    
    for(int i = 0; i <= n; i++) cout << answers[i] << ' '; cout << '\n';
    
}