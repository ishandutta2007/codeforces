/**
 *    author:  gary
 *    created: 19.01.2022 15:56:50
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
string s,t;
map<pair<char,char>,int> sum;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>s>>t;
    if(s.length()<t.length()) swap(s,t);
    n=s.length();
    m=t.length();
    LL answer=0;
    int l=0,r=0;
    rep(i,m){
        while(r!=n-1&&s[r]!=t[i]) r++,sum[II(s[r-1],s[r])]++;
        answer+=r-l+1;
        if(i&&t[i-1]!=t[i]) answer-=sum[II(t[i],t[i-1])];
        if(s[l]==t[i]){
            if(l) sum[II(s[l-1],s[l])]--;
            l++;
        }
        if(r!=n-1&&s[r]==t[i]) r++,sum[II(s[r-1],s[r])]++;
    }
    cout<<answer<<endl;
    return 0;
}