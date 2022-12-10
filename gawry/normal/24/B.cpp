#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<queue>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

int t,n,p[10]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
map<string,int> points,places[60];
bool cmp1(string x,string y){
  if(points[x]!=points[y])return points[x]<points[y];
  FOR(i,60)if(places[i][x]!=places[i][y])return places[i][x]<places[i][y];
}
bool cmp2(string x,string y){
  FOR(i,1)if(places[i][x]!=places[i][y])return places[i][x]<places[i][y];
  if(points[x]!=points[y])return points[x]<points[y];
  FOR(i,60)if(i&&places[i][x]!=places[i][y])return places[i][x]<places[i][y];
}
string s;
vector<string> all;
main() {
  cin>>t;
  FOR(k,t){
    cin>>n;
    FOR(i,n){
      cin>>s;
      all.push_back(s);
      places[i][s]++;
      if(i<10)points[s]+=p[i];
    } 
  }
  cout<<*max_element(all.begin(),all.end(),cmp1)<<endl;
  cout<<*max_element(all.begin(),all.end(),cmp2)<<endl;  
}