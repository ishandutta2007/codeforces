#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
pair<int,int> A[100000];
pair<int,int> B[100000];
map<pair<int,int> ,int> m;
int c[1001];
int d[1001];
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++)scanf("%d%d",&A[i].first,&A[i].second);
    for(int i=0;i<b;i++)scanf("%d%d",&B[i].first,&B[i].second);
    for(int i=0;i<a;i++)c[A[i].second]++;
    for(int i=0;i<b;i++)d[B[i].second]++;
    int ret=0;
    int val=0;
    for(int i=0;i<=1000;i++)ret+=min(c[i],d[i]);
    for(int i=0;i<a;i++){
        if(m.count(A[i]))m[A[i]]=m[A[i]]+1;
        else m[A[i]]=1;
    }
    for(int i=0;i<b;i++){
        if(m.count(B[i])&&m[B[i]]){
            m[B[i]]=m[B[i]]-1;
            val++;
        }
    }
    printf("%d %d\n",ret,val);
}