#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)

const int MAX=5*200*200;

int n,visited[410],phase;
bool imply[410][410];
int q[410],qs;
bool taken[410],represents[410];

void dfs(int x) {
  visited[x]=1;
  for(int i=0;i<2*n;i++)if(imply[x][i]&&!visited[i]){
    dfs(i);
  }
  q[qs++]=x;
}

bool dfs_rev(int x) {
  visited[x]=phase;
  if (visited[x^1] && visited[x^1]==phase)
    return false;
  for(int i=0;i<2*n;i++)if(imply[x^1][i])
    if (!visited[i^1] && !dfs_rev(i^1))
      return false;
  return true;
}

bool solve() {
  int i;

  qs=0;
  for (i=0; i<2*n; i++)
    visited[i]=0;
  for (i=0; i<2*n; i++)
    if (!visited[i])
      dfs(i);
  for (i=0; i<2*n; i++)
    visited[i]=represents[i]=taken[i]=false;
  for (i=2*n-1; i>=0; i--)
    if (!visited[q[i]]) {
      phase++;
      represents[q[i]]=true;
      if (!dfs_rev(q[i]))
        return false;
    }
  return true;
}

char types[30],type1[MAX],type2[MAX],s[MAX];
int alphabet,m,pos1[MAX],pos2[MAX];
bool all_C=true,all_V=true;
bool ok(){
  for(int i=0;i<2*n;i++)for(int j=0;j<2*n;j++)imply[i][j]=false;
  for(int i=0;i<n;i++){
    if(types[s[i]-'a']=='V'||all_V){
      imply[2*i][2*i+1]=true;
    }else if(types[s[i]-'a']=='C'||all_C){
      imply[2*i+1][2*i]=true;
    }
  }
  for(int i=0;i<m;i++){
    imply[2*pos1[i]+(type1[i]=='V')][2*pos2[i]+(type2[i]=='V')]=true;
    imply[2*pos2[i]+(type2[i]!='V')][2*pos1[i]+(type1[i]!='V')]=true;
  }
  //for(int i=0;i<2*n;i++)for(int j=0;j<imply[i].size();j++){
  //  printf("%d -> %d\n",i,imply[i][j]);
  //}
  //puts(s);
  bool res=solve();
  //printf("%d\n",res);
  return res;
}
char buf[1000000];
int main(){
  scanf(" %s",types);
  alphabet=strlen(types);
  for(int i=0;i<alphabet;i++){
    all_C&=types[i]=='C';
    all_V&=types[i]=='V';
  }
  scanf("%d %d\n",&n,&m);
  for(int i=0;i<m;i++){
    gets(buf);
    //puts(buf);
    char *next=buf;
    pos1[i]=pos2[i]=0;
    while(*next!=' '){
      pos1[i]=10*pos1[i]+*next-'0';
      ++next;
    }
    while(*next==' ')++next;
    type1[i]=*next;
    ++next;
    while(*next==' ')++next;
    while(*next!=' '){
      pos2[i]=10*pos2[i]+*next-'0';
      ++next;
    }
    while(*next==' ')++next;
    type2[i]=*next;
    //printf("%d %c %d %c\n",pos1[i],type1[i],pos2[i],type2[i]);
    //scanf("%d %c %d %c",&pos1[i],&type1[i],&pos2[i],&type2[i]);
    --pos1[i];
    --pos2[i];
  }
  scanf(" %s",s);
  if(ok()){
    printf("%s\n",s);
    return 0;
  }
  int pos=n-1;
  bool found=false;
  while(pos>=0){
    bool checked[256]={};
    while(s[pos]<'a'+alphabet-1){
      ++s[pos];
      if(!checked[types[s[pos]-'a']]){
        checked[types[s[pos]-'a']]=true;
        if(ok()){
          found=true;
          break;
        }
      }
    }
    if(found)break;
    s[pos]='?';
    --pos;
  }
  if(!found){
    printf("-1\n");
    return 0;
  }
  ++pos;
  while(s[pos]){
    s[pos]='a';
    if(!ok()){
      while(types[s[pos]-'a']==types[0]){
        ++s[pos];
      }
    }
    ++pos;
  }
  printf("%s\n",s);
  return 0;
}