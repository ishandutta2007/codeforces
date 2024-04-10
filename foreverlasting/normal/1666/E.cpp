#include<bits/stdc++.h>
using namespace std;
#define res int
#define pb push_back
#define LL long long
#define gc getchar
#define Pair pair<int,int>
#define fi first
#define mp make_pair
#define se second
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
inline int read(){
    res s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=1e5+10;
int L,n;
int a[N],pos[N],pot[N];
int main(){
    L=read(),n=read();
    for(res i=0;i<n;i++)a[i]=read();
    res l=1,r=L,ret=0;
    while(l<=r){
        res mid=(l+r)>>1,fl=0;
        pot[n]=L;
        for(res i=n-1;~i;i--){
            pot[i]=max(i==0?0:a[i-1],pot[i+1]-mid);
            if(pot[i]>a[i]){fl=1;break;}
        }
        if(pot[0])fl=1;
        if(!fl)r=mid-1,ret=mid;
        else l=mid+1;
    }
    pot[n]=L;
    for(res i=n-1;~i;i--)pot[i]=max(i==0?0:a[i-1],pot[i+1]-ret);
    l=1,r=L,ret=0;
    while(l<=r){
        res mid=(l+r)>>1,fl=0;
        pos[n]=L;
        for(res i=n-1;~i;i--){
            pos[i]=min(a[i],pos[i+1]-mid);
            if(pos[i]<(i==0?0:a[i-1])){fl=1;break;}
        }
        if(!fl)l=mid+1,ret=mid;
        else r=mid-1;
    }
    pos[n]=L;
    for(res i=n-1;~i;i--){
        pos[i]=min(a[i],pos[i+1]-ret);
    }
    res cur=0;
    for(res i=0;i<n;i++){
        res now=cur+ret;
        now=min(now,pos[i+1]),now=max(now,pot[i+1]);
        printf("%d %d\n",cur,now),cur=now;
    }
    return 0;
}