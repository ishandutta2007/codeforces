#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
    int n,t;
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for (int x=0;x<n;x+=2){
        printf("%d ",v[x]);
    }
    if (n&1)n--;
    for (int x=n-1;x>0;x-=2){
        printf("%d ",v[x]);
    }
}