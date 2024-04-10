#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int arr[1000002];
int what[4194304];

void out(int mask) {
    for(int i=31;i>=0;--i)
        cout << ((mask&(1LL<<i))>0);
    cout << endl;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    memset(what,-1,sizeof(what));
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        what[arr[i]]=arr[i];
    }
    int pp=22,up=1<<pp;
    for(int i=0;i<up;++i) {
        int bit=1,k=i;
        while(what[i]==-1&&k) {
            if (k&1) what[i]=what[i-bit];
            k>>=1; bit<<=1;
        }
    }
    int left=((1<<(31-pp))-1)<<pp;
//  cout << left << endl;
//  out(left);
    for(int i=0;i<n;++i) {
        if (i) printf(" ");
        printf("%d",what[((~arr[i])-(1<<31))-left]);
//      out(((~arr[i])-(1<<31))-left);
//      cout << ((~arr[i])-(1<<31))-left << endl;
    }
    printf("\n");
    return 0;
}