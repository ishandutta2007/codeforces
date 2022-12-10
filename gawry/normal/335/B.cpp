#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<string>
using namespace std;
char s[1000000];
int cnt[26],t[3000][3000],n;
int f(int from,int to){
  if(from<0||to>=n)return 0;
  if(t[from][to]>-1)return t[from][to];
  t[from][to]=max(f(from-1,to),f(from,to+1));
  if(s[from]==s[to])t[from][to]=max(t[from][to],2+f(from-1,to+1));
  return t[from][to];
}
string g(int from,int to){
  if(from<0||to>=n)return "";
  if(t[from][to]==f(from-1,to))return g(from-1,to);
  if(t[from][to]==f(from,to+1))return g(from,to+1);
  return string(1,s[to])+g(from-1,to+1);
}
int main(){
  scanf("%s",s);
  n=strlen(s);
  for(int i=0;i<n;i++)++cnt[s[i]-'a'];
  for(int i=0;i<26;i++)if(cnt[i]>=100){
    for(int j=0;j<100;j++)printf("%c",'a'+i);
    printf("\n");
    return 0;
  }
  assert(n<=2600);
  memset(t,-1,sizeof(t));
  int ans_even=0,ans_odd=0;
  for(int i=0;i<n;i++)ans_even=max(ans_even,f(i,i+1)),ans_odd=max(ans_odd,1+f(i-1,i+1));
//  printf("%d %d\n",ans_even,ans_odd);
  string even,odd;
  for(int i=0;i<n;i++)if(f(i,i+1)==ans_even){
    string s=g(i,i+1);
    s=s.substr(0,50);
    even=s;
    reverse(even.begin(),even.end());
    even+=s;
    break;
  }
  for(int i=0;i<n;i++)if(1+f(i-1,i+1)==ans_odd){
    string t=g(i-1,i+1);
    t=t.substr(0,49);
    odd=t;
    reverse(odd.begin(),odd.end());
    odd+=s[i];
    odd+=t;
    break;
  }
  if(ans_even>=100)printf("%s\n",even.c_str());else printf("%s\n",(even.length()>odd.length()?even:odd).c_str());
  return 0;
}