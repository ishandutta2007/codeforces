//2019.2.21 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _abs(const res &x) {
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN {
    int n;
    int a[N];
    LL ans;
    char str[N];
    struct SA{
        int rnk[N],buc[N],sa[N],hei[N],fi[N],se[N],m,str[N];
        inline void get_SA(){
            m=2000;
            for(res i=1;i<=n;i++)buc[fi[i]=str[i]]++;
            for(res i=2;i<=m;i++)buc[i]+=buc[i-1];
            for(res i=n;i;i--)sa[buc[fi[i]]--]=i;
            for(res k=1;k<=n;k<<=1){
                res num=0;
                for(res i=n-k+1;i<=n;i++)se[++num]=i;
                for(res i=1;i<=n;i++)if(sa[i]>k)se[++num]=sa[i]-k;
                memset(buc,0,sizeof(buc));
                for(res i=1;i<=n;i++)buc[fi[i]]++;
                for(res i=2;i<=m;i++)buc[i]+=buc[i-1];
                for(res i=n;i;i--)sa[buc[fi[se[i]]]--]=se[i],se[i]=0;
                swap(fi,se);
                fi[sa[1]]=1;
                num=1;
                for(res i=2;i<=n;i++)fi[sa[i]]=(se[sa[i]]==se[sa[i-1]]&&se[sa[i]+k]==se[sa[i-1]+k])?num:++num;
                if(num==n)break;
                m=num;
            }
        }
        inline void get_hei(){
            res k=0;
            for(res i=1;i<=n;i++)rnk[sa[i]]=i;
            for(res i=1;i<=n;i++){
                if(rnk[i]==1)continue;
                if(k)k--;
                res j=sa[rnk[i]-1];
                while(j+k<=n&&i+k<=n&&str[i+k]==str[j+k])k++;
                hei[rnk[i]]=k;
            }
        }
        int st[N][21];
        inline void PRE(){
            memset(st,inf,sizeof(st));
            for(res i=1;i<=n;i++)st[i][0]=hei[i];
            for(res j=1;j<=20;j++)
                for(res i=1;i+(1<<j)-1<=n;i++)
                    st[i][j]=_min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
        inline int query_min(const res &l,const res &r){
            res k=log2(r-l+1);
            return _min(st[l][k],st[r-(1<<k)+1][k]);
        }
        inline int LCP(const res &l,const res &r){
            return query_min(_min(rnk[l],rnk[r])+1,_max(rnk[l],rnk[r]));
        }
        inline void pre(){
            get_SA(),get_hei(),PRE();
        }
    }lcp;
    inline int getlcp(const res &l,const res &r){
        return lcp.LCP(l,r);
    }
    int st[N],top;
    inline void MAIN(){
        scanf("%s",str+1),n=strlen(str+1),ans=1LL*n*(n+1)/2;
        for(res i=1;i<=n;i++)lcp.str[i]=str[i];
        lcp.pre();
        LL sum=0;
        for(res i=1;i<=n+1;i++){
            ans+=sum;
            while(top&&lcp.hei[st[top]]>lcp.hei[i])sum-=1LL*(lcp.hei[st[top]]-lcp.hei[i])*(st[top]-st[top-1]),top--;
            sum+=lcp.hei[st[++top]=i];
        }
        printf("%lld\n",ans);
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}