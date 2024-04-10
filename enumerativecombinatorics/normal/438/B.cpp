#include<stdio.h>
#include<algorithm>
using namespace std;
int UF[110000];
int FIND(int a){
    if(UF[a]<0)return a;
    return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
    a=FIND(a);b=FIND(b);
    if(a==b)return;
    UF[a]+=UF[b];
    UF[b]=a;
}
int c[110000];
pair<int,pair<int,int> > e[110000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++)UF[i]=-1;
    for(int i=0;i<a;i++)scanf("%d",c+i);
    for(int i=0;i<b;i++){
        int p,q;scanf("%d%d",&p,&q);
        p--;q--;
        e[i]=make_pair(-min(c[p],c[q]),make_pair(p,q));
    }
    std::sort(e,e+b);
    long long val=0;
    for(int i=0;i<b;i++){
        int p=e[i].second.first;
        int q=e[i].second.second;
        int r=-e[i].first;
        if(FIND(p)!=FIND(q)){
            int sp=-UF[FIND(p)];
            int sq=-UF[FIND(q)];
            val+=(long long)sp*sq*r;
            UNION(p,q);
        }
    }
    printf("%.12f\n",(double)val/a/(a-1)*2);
}