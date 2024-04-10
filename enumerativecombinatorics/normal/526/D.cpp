#include<stdio.h>
#include<algorithm>
using namespace std;
char c[1100000];
int n;
int sa_k;
int rank[1110000];
int tmp[1110000];
int sa[1110000];
int lcp[1110000];
bool compare_sa(int i,int j){
    if(rank[i]!=rank[j])return rank[i]<rank[j];
    else{
        int ri=i+sa_k<=n?rank[i+sa_k]:-1;
        int rj=j+sa_k<=n?rank[j+sa_k]:-1;
        return ri<rj;
    }
}
void construct_sa(){
    for(int i=0;i<=n;i++){
        sa[i]=i;
        rank[i]=i<n?c[i]:-1;
    }
    for(sa_k=1;sa_k<=n;sa_k*=2){
        sort(sa,sa+n+1,compare_sa);
        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++){
            tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=n;i++){
            rank[i]=tmp[i];
        }
    }
}
void construct_lcp(){
    for(int i=0;i<=n;i++)rank[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++){
        int j=sa[rank[i]-1];
        if(h>0)h--;
        for(;j+h<n&&i+h<n;h++){
            if(c[j+h]!=c[i+h])break;
        }
        lcp[rank[i]-1]=h;
    }
}
char ret[1100000];
int rev[1100000];
int segtree[2100000];
int query(int a,int b,int c,int d,int e){
    if(d<a||b<c)return 999999999;
    if(c<=a&&b<=d)return segtree[e];
    return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
    a+=1048576;
    while(a){
        segtree[a]=min(segtree[a],b);
        a/=2;
    }
}
pair<int,int>ev[2100000];
int fail[1100000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    scanf("%s",c);
    n=a;
    //fail[0]=-1;
    for(int i=1;i<a;i++){
        int at=fail[i-1];
        while(at>=0){
            if(c[i]==c[at]){
                fail[i]=at+1;break;
            }else if(at==0)break;
            at=fail[at-1];
        }
    }
    fail[0]=0;
//  for(int i=0;i<a;i++)printf("%d\n",fail[i]);
    for(int i=0;i<a;i++)ret[i]='0';
    int sz=0;
    for(int i=b;i<=a;i+=b){
        int len=i/b;
        int t=i-fail[i-1];
    //  printf("%d %d\n",i,t);
        //printf("%d %d\n",i,q);
        if(len%t==0){
            
            int left=0;
            int right=len+1;
            while(left+1<right){
                int M=(left+right)/2;
                if(len%(i+M-fail[i-1+M])==0)left=M;
                else right=M;
            }
        //  printf("%d %d\n",i-1,i+left);
            ev[sz++]=make_pair(i-1,1);
            ev[sz++]=make_pair(i+left,-1);
        }
    }
    std::sort(ev,ev+sz);
    int now=0;
    int at=0;
    for(int i=0;i<a;i++){
        while(at<sz&&ev[at].first==i){
            now+=ev[at].second;
            at++;
        }
        if(now)ret[i]='1';
    }
    printf("%s\n",ret);
}