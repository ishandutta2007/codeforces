/**
 *    author:  gary
 *    created: 09.08.2022 17:57:47
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL unsigned long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const LL iv5=14757395258967641293;
struct num{
    LL v[10];
    num(){memset(v,0,sizeof(v));}
};
num operator * (num A,num B){
    num C;
    rep(i,10) rep(j,10) C.v[(i+j)%10]+=A.v[i]*B.v[j];
    return C;
}
num operator + (num A,num B){
    num C;
    rep(i,10) C.v[i]=A.v[i]+B.v[i];
    return C;
}
LL phi10[5]={1,18446744073709551615,1,18446744073709551615,1};
LL getmod(num A){
    rl(i,9,4){
        LL t=A.v[i];
        rep(j,5){
            A.v[i-j]-=t*phi10[j];
        }
    }
    rep(j,4) if(j) assert(A.v[j]==0);
    return A.v[0];
}
LL quick(LL A,LL B){
    if(B==0) return 1;
    LL rest=quick(A,B>>1);
    rest=rest*rest;
    if(B&1) rest=rest*A;
    return rest;
}
num quick(num A,int B){
    if(B==0) {
        num rest;
        rest.v[0]=1;
        return rest;
    }
    num rest=quick(A,B>>1);
    rest=rest*rest;
    if(B&1) rest=rest*A;
    return rest;
}
num mat[10][10];
num v[100000];
num tmp[100000];
void FWT(){
    int pw=1;
    rep(i,5){
        for(int j=0;j<100000;j+=pw*10){
            rep(f,pw){
                rep(k,10){
                    tmp[f+j+pw*k]=num();
                }
                rep(k,10){
                    rep(l,10){
                        tmp[f+j+pw*l]=tmp[f+j+pw*l]+v[f+j+pw*k]*mat[k][l];
                    }
                }
                rep(k,10){
                    v[f+j+pw*k]=tmp[f+j+pw*k];
                }
            }
        }
        pw=pw*10;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i,10) rep(j,10) mat[i][j].v[(i*j)%10]=1;
    int n;
    cin>>n;
    rb(i,1,n){
        int xi;
        cin>>xi;
        v[xi].v[0]++;
    }
    FWT();
    rep(i,100000){
        v[i]=quick(v[i],n);
    }
    rep(i,10) rep(j,10) {mat[i][j]=num();mat[i][j].v[(20-i*j%10)%10]=1;}
    FWT();
    rep(i,n){
        cout<<(((getmod(v[i])>>5)*iv5*iv5*iv5*iv5*iv5)&((1ll<<58)-1))<<'\n';
    }
    return 0;
}