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
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int k,n[3],t[3];
bool ok(int deadline){
  vector<int> available;
  FOR(i,k)available.push_back(0);
  for(int z=0;z<3;z++){
    vector<int> next;
    sort(available.begin(),available.end());
    int pos=0;
    priority_queue<int> machine;
    for(int i=0;i<n[z];i++)machine.push(0);
    while(pos<available.size()){
      int time=-machine.top();
      machine.pop();
      time=max(time,available[pos]);
      machine.push(-time-t[z]);
      next.push_back(time+t[z]);
      ++pos;
    }
    available=next;
  }
  return *max_element(available.begin(),available.end())<=deadline;
}
int main(){
  cin>>k>>n[0]>>n[1]>>n[2]>>t[0]>>t[1]>>t[2];
  int from=0,to=1000000000;
  while(from+1<to){
    int middle=(from+to)/2;
    if(ok(middle))to=middle;else from=middle;
  }
  cout<<to<<endl;
  return 0;
}