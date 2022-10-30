#include<stdio.h>
#include<algorithm>
using namespace std;
int cart[1000][1000];
int size[1000];
pair<int,int> p[1000];
pair<int,int> q[1000];
pair<int,int> s[1000];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int P=0;
    int Q=0;
    for(int i=0;i<a;i++){
        int c,d;
        scanf("%d%d",&c,&d);
        if(d==1)p[P++]=make_pair(c,i);
        if(d==2)q[Q++]=make_pair(c,i);
        s[i]=make_pair(c,d);
    }
    std::sort(p,p+P);
    std::sort(q,q+Q);
    if(P>=b){
        for(int i=0;i<b;i++){
            cart[i][size[i]++]=p[i+P-b].second;
        }
        for(int i=b;i<P;i++){
            cart[0][size[0]++]=p[P-1-i].second;
        }
        for(int i=0;i<Q;i++){
            cart[0][size[0]++]=q[i].second;
        }
    }else{
        for(int i=0;i<P;i++)cart[i][size[i]++]=p[i].second;
        for(int i=P;i<b;i++){
            cart[i][size[i]++]=q[i-P].second;
        }
        for(int i=b-P;i<Q;i++){
            cart[b-1][size[b-1]++]=q[i].second;
        }
    }
    double ret=0;
    for(int i=0;i<b;i++){
        int M=1999999999;
        double val=0;
        for(int j=0;j<size[i];j++){
            val+=s[cart[i][j]].first;
            M=min(M,s[cart[i][j]].first);
        }
        if(s[cart[i][0]].second==1)val-=(double)M/2.0;
        ret+=val;
    }
    printf("%.1f\n",ret);
    for(int i=0;i<b;i++){
        printf("%d",size[i]);
        for(int j=0;j<size[i];j++)printf(" %d",cart[i][j]+1);
        printf("\n");
    }
}