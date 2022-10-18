#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <ctime>

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,ans=2000;
    char mas[1002]={0};
    cin >> n >> mas;
    int h=0,t=0;
    for(int i=0;i<n;i++)
        if (mas[i]=='H') h++;
        else t++;
    for(int i=0;i<n-t+1;i++)
    {
        int kol=0;
        for(int j=i;j<i+t;j++)
            if (mas[j]=='H') kol++;
        if (kol<ans) ans=kol;
    }
    for(int i=0;i<n-h+1;i++)
    {
        int kol=0;
        for(int j=i;j<i+h;j++)
            if (mas[j]=='T') kol++;
        if (kol<ans) ans=kol;
    }
    cout << ans << endl;
    return 0;
}