/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

vector<long long> pd;
long long N;

int main(int argc, char *argv[]){
  cin >> N;
  for(long long i = 2; i*i <= N; i++){
    while(N%i==0){ pd.push_back(i); N/=i; }
  }
  if(N>1) pd.push_back(N);
  if(pd.size() > 2){
    cout << "1" << endl;
    cout << pd[0] * pd[1] << endl;
    return 0;
  }
  if(pd.size() == 2)  printf("2\n");
  if(pd.size() <  2)  printf("1\n0\n");
  return 0;
}