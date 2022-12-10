#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
char s[100001];
int k,n;
string ans;
main(){
  scanf(" %s %d",s,&k);
  n=strlen(s);
  vector<int> active;
  for(int i=0;i<n;i++)active.push_back(i);
  while(k>0){
    long long cnt[26]={};
    for(int i=0;i<active.size();i++)if(active[i]+ans.size()<n)
    cnt[s[active[i]+ans.size()]-'a']+=n-active[i]-ans.size();
    int pos=0;
    while(pos<26&&cnt[pos]<k){
      k-=cnt[pos];
      pos++;
    }
    if(pos==26){
      puts("No such line.");
      return 0;
    }
    vector<int> tmp;
    for(int i=0;i<active.size();i++)if(active[i]+ans.size()<n&&s[active[i]+ans.size()]=='a'+pos)tmp.push_back(active[i]);
    ans+='a'+pos;
    swap(active,tmp);
    k-=active.size();
  }
  printf("%s\n",ans.c_str());
}