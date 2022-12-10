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
int n;
string t[8]={
"Vaporeon", "Jolteon", "Flareon", "Espeon", "Umbreon", "Leafeon", "Glaceon", "Sylveon"
};
string s;
int main(){
  cin>>n>>s;
  int pos=0;
  while(1){
    if(t[pos].size()==s.size()){
      t[pos][0]=t[pos][0]-'A'+'a';
      int i=0;
      while(i<s.size()&&(s[i]==t[pos][i]||s[i]=='.')){
        ++i;
      }
      if(i==s.size())break;
    }
    ++pos;
  }
  cout<<t[pos]<<endl;
  return 0;
}