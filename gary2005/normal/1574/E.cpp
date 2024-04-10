/**
 *    author:  gary
 *    created: 20.09.2021 22:34:44
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
const int MOD=998244353;
int quick(int A,int B){
    if(B==0) return 1;
    int tmp=quick(A,B>>1);
    tmp=1ll*tmp*tmp%MOD;
    if(B&1) tmp=1ll*tmp*A%MOD;
    return tmp;
}
map<mp,int> have;
int cnt[2][2][2];
int cntr[1000000][2][2];
int cntc[1000000][2][2];
int cr[1000000],cc[1000000];
int zr,zc;
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int badc,badr;
void query(){
    int rest=0;
    {
        if(!badr)
        add(rest,quick(2,zr));
        if(!badc)
        add(rest,quick(2,zc));
        if(!badr&&!badc){
        bool ok=cnt[0][0][1]||cnt[1][1][1]||cnt[0][1][0]||cnt[1][0][0];
        if(!ok)
        add(rest,MOD-1);
        ok=cnt[0][0][0]||cnt[1][1][0]||cnt[0][1][1]||cnt[1][0][1];
        if(!ok)
        add(rest,MOD-1);
        }
    }
    printf("%d\n",rest);
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    badc=badr=0;
    zr=n;
    zc=m;
    rb(q,1,k){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        x--;
        y--;
        if(t==-1){
            if(have.find(II(x,y))==have.end());
            else{
                cr[x]--;
                zr+=cr[x]==0;
                cc[y]--;
                zc+=cc[y]==0;
                int val=have[II(x,y)];
                cnt[x%2][y%2][val]--;
                badr-=(cntr[x][y%2][0]&&cntr[x][y%2][1])||(cntr[x][(y%2)^1][0]&&cntr[x][(y%2)^1][1])||(cntr[x][y%2][0]&&cntr[x][(y%2)^1][0])||(cntr[x][y%2][1]&&cntr[x][(y%2)^1][1]);
                cntr[x][y%2][val]--;
                badr+=(cntr[x][y%2][0]&&cntr[x][y%2][1])||(cntr[x][(y%2)^1][0]&&cntr[x][(y%2)^1][1])||(cntr[x][y%2][0]&&cntr[x][(y%2)^1][0])||(cntr[x][y%2][1]&&cntr[x][(y%2)^1][1]);
                badc-=(cntc[y][x%2][0]&&cntc[y][x%2][1])||(cntc[y][(x%2)^1][0]&&cntc[y][(x%2)^1][1])||(cntc[y][x%2][0]&&cntc[y][(x%2)^1][0])||(cntc[y][x&1][1]&&cntc[y][(x%2)^1][1]);
                cntc[y][x%2][val]--;
                badc+=(cntc[y][x%2][0]&&cntc[y][x%2][1])||(cntc[y][(x%2)^1][0]&&cntc[y][(x%2)^1][1])||(cntc[y][x%2][0]&&cntc[y][(x%2)^1][0])||(cntc[y][x&1][1]&&cntc[y][(x%2)^1][1]);
                have.erase(II(x,y));
            }
        }
        else{
            if(have.find(II(x,y))!=have.end()){
                int val=have[II(x,y)];
                cnt[x%2][y%2][val]--;
                badr-=(cntr[x][y%2][0]&&cntr[x][y%2][1])||(cntr[x][(y%2)^1][0]&&cntr[x][(y%2)^1][1])||(cntr[x][y%2][0]&&cntr[x][(y%2)^1][0])||(cntr[x][y%2][1]&&cntr[x][(y%2)^1][1]);
                cntr[x][y%2][val]--;
                badr+=(cntr[x][y%2][0]&&cntr[x][y%2][1])||(cntr[x][(y%2)^1][0]&&cntr[x][(y%2)^1][1])||(cntr[x][y%2][0]&&cntr[x][(y%2)^1][0])||(cntr[x][y%2][1]&&cntr[x][(y%2)^1][1]);
                badc-=(cntc[y][x%2][0]&&cntc[y][x%2][1])||(cntc[y][(x%2)^1][0]&&cntc[y][(x%2)^1][1])||(cntc[y][x%2][0]&&cntc[y][(x%2)^1][0])||(cntc[y][x&1][1]&&cntc[y][(x%2)^1][1]);
                cntc[y][x%2][val]--;
                badc+=(cntc[y][x%2][0]&&cntc[y][x%2][1])||(cntc[y][(x%2)^1][0]&&cntc[y][(x%2)^1][1])||(cntc[y][x%2][0]&&cntc[y][(x%2)^1][0])||(cntc[y][x&1][1]&&cntc[y][(x%2)^1][1]);
                have.erase(II(x,y));
            }
            else{
            cr[x]++;
            zr-=cr[x]==1;
            cc[y]++;
            zc-=cc[y]==1;
            }
            have[II(x,y)]=t;
            int val=t;
            cnt[x%2][y%2][val]++;
                badr-=(cntr[x][y%2][0]&&cntr[x][y%2][1])||(cntr[x][(y%2)^1][0]&&cntr[x][(y%2)^1][1])||(cntr[x][y%2][0]&&cntr[x][(y%2)^1][0])||(cntr[x][y%2][1]&&cntr[x][(y%2)^1][1]);
                cntr[x][y%2][val]++;
                badr+=(cntr[x][y%2][0]&&cntr[x][y%2][1])||(cntr[x][(y%2)^1][0]&&cntr[x][(y%2)^1][1])||(cntr[x][y%2][0]&&cntr[x][(y%2)^1][0])||(cntr[x][y%2][1]&&cntr[x][(y%2)^1][1]);
                badc-=(cntc[y][x%2][0]&&cntc[y][x%2][1])||(cntc[y][(x%2)^1][0]&&cntc[y][(x%2)^1][1])||(cntc[y][x%2][0]&&cntc[y][(x%2)^1][0])||(cntc[y][x&1][1]&&cntc[y][(x%2)^1][1]);
                cntc[y][x%2][val]++;
                badc+=(cntc[y][x%2][0]&&cntc[y][x%2][1])||(cntc[y][(x%2)^1][0]&&cntc[y][(x%2)^1][1])||(cntc[y][x%2][0]&&cntc[y][(x%2)^1][0])||(cntc[y][x&1][1]&&cntc[y][(x%2)^1][1]);
        }
        query();
    }
    return 0;
}