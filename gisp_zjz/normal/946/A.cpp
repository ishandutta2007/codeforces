#include<bits/stdc++.h>

using namespace std;
int ans,n,k;

int main()
{
    scanf("%d",&n);
    while(n--){scanf("%d",&k); ans+=abs(k);}
    cout << ans << endl;
}