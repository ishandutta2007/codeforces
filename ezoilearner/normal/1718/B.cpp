#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

int t,n,K;
#define Maxn 105
int f[Maxn];
pii seq[10];

int main(){
    n=2;f[1]=f[2]=1;
    while(true){
        n++;f[n]=f[n-1]+f[n-2];
        if(f[n]>1e9){
            n--;break;
        }
    }
    rd(t);
    while(t--){
        int K;rd(K);
        priority_queue<pii> Q;
        ll all=0;
        rep(i,1,K){
            int x;
            rd(x);
            Q.push(pii(x,i));
            all+=x;
        }
        int at=-1;ll sum=0;
        rep(i,1,n){
            sum+=f[i];
            if(sum==all){
                at=i;break;
            }
        }
        if(at==-1)puts("NO");
        else{
            int lst=-1;bool fl=true;
            per(i,at,1){
                int cnt=0;bool hh=false;
                while(!Q.empty()){
                    pii cur=Q.top();Q.pop();
                    if(cur.SE==lst){
                        seq[++cnt]=cur;
                        continue;
                    }
                    if(cur.FR<f[i]){
                        puts("NO");
                        fl=false;
                        break;
                    }
                    cur.FR-=f[i];if(cur.FR)Q.push(cur);lst=cur.SE;
                    rep(j,1,cnt)Q.push(seq[j]);
                    hh=true;
                    break;
                }
                if(!fl)break;
                if(!hh){
                     puts("NO");
                        fl=false;
                        break;
                }
            }
            if(fl){
                puts("YES");
            }
        }
    }
    return 0;
}