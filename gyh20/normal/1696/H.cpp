#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
    re int t=0,f=0;re char v=getchar();
    while(v<'0')f|=(v=='-'),v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return f?-t:t;
}
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
    re int s=1;
    while(y){
        if(y&1)s=1ll*s*x%M;
        x=1ll*x*x%M,y>>=1;
    }return s;
}
int n,m,a[602],f[602][602],g[602][602],n1,n2,N0[602],N1[602],ans,k,inv[602],pw[602],Pos[602],cnt,S[602];
inline bool cmp(re int x,re int y){return abs(x)>abs(y);}
int main(){
    n=read(),k=read();
    for(re int i=pw[0]=1;i<=n;++i)pw[i]=pw[i-1],add(pw[i],pw[i-1]);
    for(re int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+n+1,cmp),f[0][0]=g[0][0]=1;
    for(re int i=n;i;--i){inv[i]=ksm(a[i]+M,M-2);
        N0[i]=N0[i+1]+(a[i]>=0);
        N1[i]=N1[i+1]+(a[i]<0);
    }
    for(re int i=1;i<=n;++i){
        if(a[i]>=0){
            ++n1;
            for(re int j=0;j<i;++j)
                for(re int l=1;l<=k;++l)
                    add(f[i][l],1ll*f[j][l-1]*a[i]%M);
        }
        else{
            ++n2;
            for(re int j=0;j<i;++j)
                for(re int l=1;l<=k;++l)
                    add(g[i][l],1ll*g[j][l-1]*(a[i]+M)%M);
        }cnt=0;
        for(re int p2=i+1;p2<=n+1;++p2)
            if(p2==n+1||(a[p2]<0))
                Pos[++cnt]=p2,S[cnt]=1ll*pw[N1[p2]-1]*(a[p2]+M)%M,add(S[cnt],S[cnt-1]);
        re int s1=-1;
        for(re int p0=0;p0<i;++p0)
            if(p0==0||((a[p0]>=0)^(a[i]>=0))){
                for(re int num=1,s1=-1;num<=((a[i]>=0)?n1:n2)&&num<=k;++num){
                    if((a[i]<0&&num%2==0)||(a[i]>=0&&(k-num)%2==0)){
                        if(p0!=0)continue;
                        if(a[i]>=0){
                        for(re int j=0;j<i;++j)add(ans,1ll*f[i][num]*g[j][k-num]%M*pw[n-i]%M);
                    }
                    else{
                        for(re int j=0;j<i;++j)add(ans,1ll*g[i][num]*f[j][k-num]%M*pw[n-i]%M);
                    }
                    continue;
                }
                if(a[i]>=0&&((!f[i][num])||(!g[p0][k-num])))continue;
                if(a[i]<0&&((!g[i][num])||(!f[p0][k-num])))continue;
                if(s1!=-1&&num!=k){
                    if(a[i]>=0)add(ans,1ll*s1*f[i][num]%M*g[p0][k-num]%M);
                    else add(ans,1ll*s1*g[i][num]%M*f[p0][k-num]%M);
                    continue;
                }
                s1=0;
                re int x=1,xx,xxx=1;
                if(p0)xxx=1ll*xxx*inv[p0]%M;
                re ll Pro=1ll*a[i]*(p0?a[p0]:1);
                xxx=1ll*xxx*inv[i]%M;
                    for(re int p1=i+1;p1<=n+1;++p1)
                        if(p1==n+1||(a[p1]>=0)){
                            if(num==k&&(k&1)&&p1==n+1)continue;
                            x=1ll*xxx*pw[max(0,N0[p1]-1)]%M;
                            re ll PRO=Pro;
                            if(a[i]>=0){
                                if(p0&&p1!=n+1)PRO=max(PRO,1ll*a[i]*a[p1]);
                            }
                            else{
                                if(p1!=n+1&&p0)PRO=max(PRO,1ll*a[p0]*a[p1]);
                            }
                            if(!p0&&p1!=n+1)PRO=max(PRO,1ll*a[p1]);
                            if(a[i]>=0){
                                re int l=1,r=cnt,pp=0;
                                while(l<=r){
                                    re int mid=l+r>>1;
                                    if(p0&&Pos[mid]!=n+1&&1ll*a[p0]*a[Pos[mid]]>PRO)pp=mid,l=mid+1;
                                    else r=mid-1;
                                }
                                re int vv=pp?pw[N1[Pos[pp]]-1]:pw[N1[i]];
                                if(pp)add(s1,1ll*(a[p0]+M)*x%M*S[pp]%M);
                                add(s1,1ll*(PRO%M+M)*x%M*vv%M);
                            }
                            else{
                                re int l=1,r=cnt,pp=0;
                                while(l<=r){
                                    re int mid=l+r>>1;
                                    if(p0&&Pos[mid]!=n+1&&1ll*a[i]*a[Pos[mid]]>PRO)pp=mid,l=mid+1;
                                    else r=mid-1;
                                }
                                re int vv=pp?pw[N1[Pos[pp]]-1]:pw[N1[i]-1];
                                if(pp)add(s1,1ll*(a[i]+M)*x%M*S[pp]%M);
                                add(s1,1ll*(PRO%M+M)*x%M*vv%M);
                            }
                        }
                    if(a[i]>=0)add(ans,1ll*s1*f[i][num]%M*g[p0][k-num]%M);
                    else add(ans,1ll*s1*g[i][num]%M*f[p0][k-num]%M);
            }
        }
    }
    if(k&1){
    reverse(a+1,a+n+1);
    for(re int i=n;i;--i){inv[i]=ksm(a[i]+M,M-2);
        N0[i]=N0[i+1]+(a[i]>=0);
        N1[i]=N1[i+1]+(a[i]<0);
    }memset(f,0,sizeof(f)),memset(g,0,sizeof(g)),g[0][0]=1;
    for(re int i=1;i<=n;++i){
        if(a[i]>=0){
            ++n1;
            for(re int j=0;j<i;++j)
                for(re int l=1;l<=k;++l)
                    add(f[i][l],1ll*f[j][l-1]*a[i]%M);
        }
        else{
            ++n2;
            for(re int j=0;j<i;++j)
                for(re int l=1;l<=k;++l)
                    add(g[i][l],1ll*g[j][l-1]*(a[i]+M)%M);
            add(ans,1ll*pw[N1[i]-1]*g[i][k]%M);
        }
    }
    }
    printf("%d",ans);
}