#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
long long num[100005];
int main(){
int n,m;
scanf("%d %d",&n,&m);
m--;
long long mini=INF;
for(int i=0;i<n;i++){
scanf("%lld",&num[i]);
mini=min(mini,num[i]);
}
long long dj=mini*(long long)n;
for(int i=0;i<n;i++){
num[i]-=mini;
}
for(;;){
if(!num[m]) break;
dj++;
num[m]--;
if(!m) m=n-1;
else m--;
}
num[m]+=dj;
printf("%lld",num[0]);
for(int i=1;i<n;i++){
printf(" %lld",num[i]);
}
puts("");
}