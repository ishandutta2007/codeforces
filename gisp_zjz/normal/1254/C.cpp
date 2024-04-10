#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,b[1005];
ll a[1005];
vector <int> A,B,ansA,ansB;
vector <pi> tA,tB;
ll qry(int x,int y,int z,int w){
    printf("%d %d %d %d\n",x,y,z,w);
    fflush(stdout);
    ll ret; scanf("%lld",&ret);
    return ret;
}
int main(){
    scanf("%d",&n);
    for (int i=3;i<=n;i++){
        if (qry(2,1,i,2)==1) A.pb(i); else B.pb(i);
    }
    if (A.size()){
        int m=A.size();
        for (int i=0;i<m;i++) a[i]=qry(1,1,2,A[i]);
        int pos=-1;
        for (int i=0;i<m;i++) if (pos==-1||a[i]>a[pos]) pos=i;
        tA.clear(); tB.clear();
        for (int i=0;i<m;i++){
            if (pos==i) continue;
            if (qry(2,1,A[pos],A[i])==-1) tA.pb((pi){a[i],A[i]});
            else tB.pb((pi){a[i],A[i]});
        }
        sort(tA.begin(),tA.end());
        sort(tB.begin(),tB.end());
        reverse(tB.begin(),tB.end());
        for (auto x:tA) ansA.pb(x.S); ansA.pb(A[pos]);
        for (auto x:tB) ansA.pb(x.S);
    }
    if (B.size()){
        int m=B.size();
        for (int i=0;i<m;i++) a[i]=qry(1,1,2,B[i]);
        int pos=-1;
        for (int i=0;i<m;i++) if (pos==-1||a[i]>a[pos]) pos=i;
        tA.clear(); tB.clear();
        for (int i=0;i<m;i++){
            if (pos==i) continue;
            if (qry(2,2,B[pos],B[i])==-1) tA.pb((pi){a[i],B[i]});
            else tB.pb((pi){a[i],B[i]});
        }
        sort(tA.begin(),tA.end());
        sort(tB.begin(),tB.end());
        reverse(tB.begin(),tB.end());
        for (auto x:tA) ansB.pb(x.S); ansB.pb(B[pos]);
        for (auto x:tB) ansB.pb(x.S);
    }
    printf("0 1 ");
    for (auto x:ansA) printf("%d ",x);
    printf("2 ");
    for (auto x:ansB) printf("%d ",x);
    puts("");
    return 0;
}