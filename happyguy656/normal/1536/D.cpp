#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int n,a[mxn];
set<int>st;
bool fi(int l,int r){
    if(l>r)return 0;
    auto it=st.lower_bound(l);
    if(it!=st.end()&&*it<=r)return 1;
    return 0;
}
bool can(){
    st.clear();
    for(int i=1;i<=n;++i){  
        st.insert(a[i]);
        if(i>1){
            if(a[i]>a[i-1]){
                if(fi(a[i-1]+1,a[i]-1))return 0;
            }else{
                if(fi(a[i]+1,a[i-1]-1))return 0;
            }
        }
    }
    return 1;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
        puts(can()?"yes":"no");
    }
    return 0;
}