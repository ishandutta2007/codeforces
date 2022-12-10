#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,d[1000001],cnt[10],e[1000001],c;
long long r;
void go(int left,int chosen=1){
  if(left==1){
    int a=chosen,b=c/a;    
    r-=d[c]==d[d[a]*d[b]];
    return;
  }  
  int left2=left,div=e[left],cnt=1;
  while(left2%div==0){left2/=div;cnt++;}
  left=left2;
  while(cnt--){
    go(left,chosen);
    chosen*=div;
  }
}
main(){
  scanf("%d",&n);
  for(int i=1;i<=1000000;i++)e[i]=i;
  for(int i=1;i<=1000000;i++){
    int s=0,x=i;
    while(x){s+=x%10;x/=10;}
    d[i]=s<10?s:d[s];
    if(i<=n)cnt[d[i]]++;
    if(i>1&&e[i]==i)for(int j=i;j<=1000000;j+=i)e[j]=i;    
  }
  for(int a=1;a<10;a++)for(int b=1;b<10;b++)for(int c=1;c<10;c++)if(d[c]==d[d[a]*d[b]])r+=(long long)cnt[a]*cnt[b]*cnt[c];
  for(c=1;c<=n;c++)go(c);
/*  for(int c=1;c<=n;c++)for(int a=1;a*a<=c;a++)if(c%a==0){
    int b=c/a;    
    r-=d[c]==d[d[a]*d[b]];
    if(a!=b)r-=d[c]==d[d[a]*d[b]];
  }*/
  cout<<r<<endl;
  // ile A,B,C, ze d[C]==d[d[A]d[B]], ale C!=AB  
}