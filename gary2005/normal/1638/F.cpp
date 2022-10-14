/**
 *    author:  gary
 *    created: 16.02.2022 19:51:25
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
const int MAXN=10000+2;
int n;
LL a[MAXN],b[MAXN];
int pre[MAXN],nex[MAXN];
pair<int,LL> my[MAXN];
int my2[MAXN];
int ord[MAXN];
bool cmp(int A,int B){return a[A]<a[B];}
int ddz[MAXN][MAXN],sizz[MAXN];
LL solve(){
    rb(i,1,n) b[i]=a[i];
    stack<int> sta;
    sta.push(0);
    rb(i,1,n){
        while(a[i]<=a[sta.top()]) sta.pop();
        pre[i]=sta.top()+1;
        sta.push(i);
        ord[i]=i;
    }
    sort(ord+1,ord+1+n,cmp);
    sizz[n+1]=1;
    ddz[n+1][1]=n+1;
    rl(i,n,1){
        sizz[i]=sizz[i+1];
        rb(j,1,sizz[i]) ddz[i][j]=ddz[i+1][j];
        while(a[i]<=a[ddz[i][sizz[i]]]) sizz[i]--;
        ddz[i][++sizz[i]]=i;
    }
    LL rest=0;
    rb(i_,1,n){
        int i=ord[i_];
        LL up=(i-pre[i])*a[i];
        LL ins=0;
        int siz=0;
        my[siz++]=II(i-1,-INF);
        rb(j,i,n){
            if(a[j]<a[i]) break;
            while(a[j]-a[i]<=a[ddz[j][sizz[j]]]) sizz[j]--;
            nex[j]=ddz[j][sizz[j]]-1;
            up+=a[i];
            while(siz!=1&&a[j]<=a[my[siz-1].first]){
                int tmp=my[siz-1].first;
                siz--;
                int l=my[siz-1].first+1;
                int r=j-1;
                check_max(ins,(r-l+1)*(a[tmp]-a[i]));
            }
            auto tmp=my[siz-1];
            my[siz++]=II(j,max(tmp.second,(nex[j]-tmp.first)*(a[j]-a[i])));
            check_max(rest,up+my[siz-1].second);
        }
        check_max(rest,ins+up);
    }
    return rest;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i],b[i]=a[i];
    a[0]=a[n+1]=-1e18;
    LL answer=0;
    rb(i,1,n){
        int now=i;
        LL tmp=a[i];
        while(now<=n&&a[now]>=tmp) a[now++]-=tmp;
        now=i-1;
        while(now&&a[now]>=tmp) a[now--]-=tmp;
        int siz=0;
        my2[++siz]=0;
        rb(i,1,n){
            while(a[i]<=a[my2[siz]]) siz--;
            pre[i]=my2[siz]+1;
            my2[++siz]=i;
        }
        siz=0;
        my2[++siz]=n+1;
        LL T2=0;
        LL T=0;
        rl(i,n,1){
            while(a[i]<=a[my2[siz]]) siz--;
            nex[i]=my2[siz]-1;
            my2[++siz]=i;
        }
        rb(i,1,n){
            check_max(T2,(nex[i]-pre[i]+1)*a[i]);
            T+=b[i]-a[i],a[i]=b[i];
        }
        check_max(answer,T+T2);
    }
    check_max(answer,solve());
    reverse(a+1,a+1+n);
    check_max(answer,solve());
    cout<<answer<<endl;
    return 0;
}