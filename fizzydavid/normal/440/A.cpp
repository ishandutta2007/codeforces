#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
int main()
{
    int n,a=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a^=i;
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a^=x;
    }
    cout<<a;
//  system("pause");
    return 0;
}