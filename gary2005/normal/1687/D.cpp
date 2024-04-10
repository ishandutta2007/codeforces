/**
 *    author:  gary
 *    created: 03.06.2022 22:30:51
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
const int MAXN=2e6+10;
bool ok[MAXN];
int pre[MAXN],nex[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> can;
    int n;
    cin>>n;
    rb(i,1,n){
        int ai;
        cin>>ai;
        ok[ai]=1;
    }
    n=2e6;
    fill(pre,pre+MAXN,-1);
    fill(nex,nex+MAXN,-1);
    rb(i,1,n+1) pre[i]=(ok[i]? i:pre[i-1]);
    rl(i,n,0) nex[i]=(ok[i]? i:nex[i+1]);
    rb(X,2,n){
        int A=X;
        int now=nex[0];
        bool ok=1;
        vector<mp> seg;
        vector<int> aa;
        while (true){
            int o=min(n,now+A-1);
            int x=pre[o];
            int y=nex[min(n+1,x+A)];
            // if(X==174){
            //     cout<<now<<" "<<x<<endl;
            // }
            aa.PB(A);
            seg.PB(II(now,x));
            if(y==-1){
                if(nex[x+1]!=-1){
                    ok=0;
                    break;
                }
                break;
            }
            int d=x+A;
            while(y>=d+A+A+1) d+=A+A+1,A++;
            if(pre[y-1]==x){
                
            }
            else{
                ok=0;
                break;
            }
            now=y;
            A++;
        }
        if(ok){
            A=X;
            LL d=0;
            LL L=-1e18,R=1ll*(A-1)*(A-1);
            int pt=0;
            for(auto it:seg){
                // if(X==174)
                // cout<<it.first<<" "<<it.second<<endl;
                //  y + d<=it.FIR  
                //  y + d + A-1 >=it.SEC
                while (A<aa[pt]){
                    d+=2*A-1;
                    ++A;
                }
                pt++;
                check_min(R,it.first-d);
                check_max(L,it.second-A+1-d);
                // if(X==174)
                // cout<<it.first<<" "<<it.second<<" "<<L<<" "<<R<<endl;
                d+=2*A-1;
                ++A;
            }
            // if(X==174)
            // cout<<L<<" "<<R<<endl;
            if(L<=R){
                // cout<<A<<' '<<R<<endl;
                int D=nex[0]-R;
                A=X;
                A--;
                cout<<1ll*A*A+D-nex[0]<<endl;
                return 0;
            }
        }
    }
    return 0;
}