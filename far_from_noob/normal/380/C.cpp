#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > ii;
#define repi(i, a, b)    for(int i = a; i < b; i++)
#define repd(i, a, b)    for(int i = b-1; i >= a; i--)   
#define rep(i, n)        for(int i = 0; i < n; ++i)
#define ll               long long int
#define I                iterator
#define lf               long double
#define pb               push_back
#define pq               priority_queue
#define all(c)           (c).begin(), (c).end()
#define tr(c, it)        for(auto it = c.begin(); it != c.end(); ++it)
#define mp               make_pair
#define ff               first
#define ss               second

const int N = 1000001;

int t[4*N], o[4*N], c[4*N];
string str;

void build(int id, int l, int r){
    if(r - l < 2){
        if(str.at(l) == '('){
            t[id] = 0;
            o[id] = 1;
        }else{
            t[id]=0;
            c[id]=1;
        }

        // cout << str.substr(l, r-l)<<endl;
        // cout << "["<<l<<", "<<r<<") : t = "<<t[id]<<" o = "<<o[id]<<" c = "<<c[id]<<" id = "<<id<<endl;
        return ;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid, r);
    int tmp = min(o[2*id], c[2*id + 1]);
    t[id] = t[2*id] + t[2*id + 1] + 2*tmp;
    o[id] = o[2*id] + o[2*id + 1] - tmp;
    c[id] = c[2*id] + c[2*id + 1] - tmp;
    // cout << str.substr(l, r-l)<<endl;
    // cout << "["<<l<<", "<<r<<") : t = "<<t[id]<<" o = "<<o[id]<<" c = "<<c[id]<<" id = "<<id<<endl;
}

pair<int, ii> query(int id, int l, int r, int start, int end){
    
    if((end <= l) || (start >= r)){
    //     cout << str.substr(l, r-l)<<endl;
    // cout << "["<<l<<", "<<r<<") : t = "<<t[id]<<" o = "<<o[id]<<" c = "<<c[id]<<" id = "<<id<<endl;
        return mp(0, mp(0, 0));
    }
    if((l >= start)&&(r <= end)){
        // cout << str.substr(l, r-l)<<endl;
    // cout << "["<<l<<", "<<r<<") : t = "<<t[id]<<" o = "<<o[id]<<" c = "<<c[id]<<" id = "<<id<<endl;
        return mp(t[id], mp(o[id], c[id]));
    }
    int mid = (l+r)/2;
    pair<int, ii> a = query(2*id, l, mid, start, end), b = query(2*id+1, mid, r, start, end);
    int tmp = min(a.ss.ff, b.ss.ss);
    int T = a.ff + b.ff + 2*tmp;
    int O = a.ss.ff + b.ss.ff - tmp;
    int C = a.ss.ss + b.ss.ss - tmp;
    // cout << str.substr(l, r-l)<<endl;
    // cout << "["<<l<<", "<<r<<") : t = "<<t[id]<<" o = "<<o[id]<<" c = "<<c[id]<<" id = "<<id<<endl;
    return mp(T, mp(O, C));
}

int main(){
    
    getline(cin, str);
    int n = str.length();
    build(1, 0, n);
    // for(int i = 1; i < 24; i++){
    //     cout << t[i] << " ";
    // }
    // cout << endl;
    int q;
    cin >> q;
    rep(i, q){
        int l, r;
        cin >> l >> r;
        pair<int, ii> ans = query(1, 0, n,l-1, r);
        cout << ans.ff<<endl;
    }
    return 0;
}