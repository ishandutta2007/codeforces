#include<stdio.h>
#include<algorithm>
using namespace std;
pair<int,pair<int,int> > dat[200000];
pair<int,pair<long long,int> >c[200000];
int L[100000];
int R[100000];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d%d",&dat[i].first,&dat[i].second.first);
        dat[i].second.first=-dat[i].second.first;
        dat[i].second.second=i;
    }
    std::sort(dat,dat+a);
    long long now=0;
    int ren=0;
    int at=0;
    for(int i=0;i<a;i++){
        if(i==0||dat[i].first!=dat[i-1].first){
            if(i){
                c[at+a]=make_pair(ren+1,make_pair(-now,dat[i-1].first));
                at++;
            }
            now=-dat[i].second.first;
            ren=1;
            c[i]=make_pair(ren,make_pair(-now,dat[i].first));
        }else{
            now-=dat[i].second.first;
            ren++;
            c[i]=make_pair(ren,make_pair(-now,dat[i].first));
        }
    }
    c[at+a]=make_pair(ren+1,make_pair(-now,dat[a-1].first));
    at++;
    std::sort(c,c+at+a);
    long long ret=0;
    int p=0;
    int q=0;
    int size=0;
    for(int i=0;i<at+a-1;i++){
        if(c[i].first==c[i+1].first){
            if(ret<-c[i].second.first-c[i+1].second.first){
                ret=-c[i].second.first-c[i+1].second.first;
                p=c[i].second.second;
                q=c[i+1].second.second;
                size=c[i].first;
            }
        }
    }
    printf("%I64d\n",ret);
    int P=0;
    int Q=0;
    for(int i=0;i<a;i++){
        if(p==dat[i].first){
            L[P++]=dat[i].second.second;
        }
        if(q==dat[i].first){
            R[Q++]=dat[i].second.second;
        }
    }
    if(P<size&&Q<size){
        size--;
        printf("%d\n",size+size);
        for(int i=0;i<size;i++){
            if(i)printf(" ");
            printf("%d %d",L[i]+1,R[i]+1);
        }
        printf("\n");
    }
    else if(P>=size&&Q<size){
        size--;
        printf("%d\n",size+size+1);
        printf("%d",L[size]+1);
        for(int i=0;i<size;i++){
            printf(" %d %d",R[i]+1,L[i]+1);
        }
        printf("\n");
    }
    else if(P<size&&Q>=size){
        size--;
        printf("%d\n",size+size+1);
        printf("%d",R[size]+1);
        for(int i=0;i<size;i++){
            printf(" %d %d",L[i]+1,R[i]+1);
        }
        printf("\n");
    }
    else if(P>=size&&Q>=size){
        printf("%d\n",size+size);
        for(int i=0;i<size;i++){
            if(i)printf(" ");
            printf("%d %d",L[i]+1,R[i]+1);
        }
        printf("\n");
    }
}