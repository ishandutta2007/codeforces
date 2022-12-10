#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long int64;
typedef pair<int,int> p2;
char s[110000];
int k,L,R,l[510],r[510],pos_from[510],pos_to[510],cnt_from[510],cnt_to[510],sum[110000],good;
char c[510];
main(){
  scanf(" %s %d %d %d",s,&k,&L,&R);
  for(int i=0;i<k;i++)scanf(" %c %d %d",&c[i],&l[i],&r[i]);
  int64 ans=0;
  for(int i=0;s[i];i++){
    good+=L<=sum[i]&&sum[i]<=R;
    for(int j=0;j<k;j++){
      cnt_from[j]+=c[j]==s[i];
      cnt_to[j]+=c[j]==s[i];
      //printf("%d %d  %d %d\n",cnt_from[j],cnt_to[j],pos_from[j],pos_to[j]);
      while(cnt_from[j]>r[j]){
        cnt_from[j]-=s[pos_from[j]]==c[j];
        good-=L<=sum[pos_from[j]]&&sum[pos_from[j]]<=R;
        --sum[pos_from[j]];
        good+=L<=sum[pos_from[j]]&&sum[pos_from[j]]<=R;
        ++pos_from[j];
      }
      while(pos_to[j]<=i&&cnt_to[j]>=l[j]){
        cnt_to[j]-=s[pos_to[j]]==c[j];
        good-=L<=sum[pos_to[j]]&&sum[pos_to[j]]<=R;
        ++sum[pos_to[j]];
        good+=L<=sum[pos_to[j]]&&sum[pos_to[j]]<=R;
        ++pos_to[j];
      }
    }
//for(int j=0;j<=i;j++)printf("%d ",sum[j]);
//puts("");
//cout<<good<<endl;
    ans+=good;
  }
  cout<<ans<<endl;
}