#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

char mas[100003]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%s",mas);
    ll kol[300]={0},l=strlen(mas);
    for(int i=0;i<l;i++)
    {
        kol[mas[i]]++;
    }
    ll ans=0;
    for(int i=0;i<300;i++)
        ans+=kol[i]*kol[i];
    cout << ans << endl;
    return 0;
}