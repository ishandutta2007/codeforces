/**
 *    author:  gary
 *    created: 12.09.2021 22:32:07
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
const int MAXN=1e5+1;
int n;
string a,b;
void solve(){
    scanf("%d",&n);
    cin>>a>>b;
    int answer=0;
    rep(i,n){
        if(a[i]!=b[i]) answer+=2;
        else{
            if(a[i]=='0'){
                answer++;
                if(i&&a[i-1]=='1'&&b[i-1]=='1'){
                    answer++;
                }
                else{
                    if(i!=n-1&&a[i+1]=='1'&&b[i+1]=='1'){
                        a[i+1]='x';
                        b[i+1]='x';
                        answer++;
                    }
                }
            }
        }
    }
    printf("%d\n",answer);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}