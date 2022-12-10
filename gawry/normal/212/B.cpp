#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define MAX 1100000
char s[MAX];
map<int,int> cnt;
int m,code[10000],prev[26],t[26];
bool cmp(int x,int y){
  return prev[x]<prev[y];
}
main(){
  scanf("%s %d",s,&m);
  for(int i=0;i<m;i++){
    char buf[30];
    scanf("%s",buf);
    code[i]=0;
    for(int j=0;buf[j];j++)code[i]|=1<<buf[j]-'a';
    cnt[code[i]]=0;
  }
  for(int j=0;j<26;j++)prev[j]=-1;
  for(int i=0;s[i];i++){
    prev[s[i]-'a']=i;
    if(s[i+1]&&s[i]==s[i+1])continue;
    for(int j=0;j<26;j++)t[j]=j;
    sort(t,t+26,cmp);
    int code=0;
    for(int j=25;j>=0&&prev[t[j]]>=0;j--){
      code|=1<<t[j];
      if(s[i+1]&&code&1<<s[i+1]-'a')break;
      map<int,int>::iterator it=cnt.find(code);
      if(it!=cnt.end())++it->second;
    }
  }
  for(int i=0;i<m;i++)printf("%d\n",cnt[code[i]]);
}