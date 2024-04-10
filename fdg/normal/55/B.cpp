#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cstring>

#define ll long long

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);}

char mas[4]={0};
ll ans;
bool finded=false;

void rec(ll nums[],int cur = 0)
{
    if (cur==3)
    {
        if (finded==false||ans>nums[0]) ans=nums[0];
        finded=true;
        return;
    }
    for(int i=0;i<4-cur;i++)
    {
        for(int j=i+1;j<4-cur;j++)
        {
            ll nm[4]={0},kol=0;
            for(int t=0;t<4-cur;t++)
            {
                if (t==i||t==j) continue;
                nm[kol++]=nums[t];
            }
            if (mas[cur]=='+') nm[kol++]=nums[i]+nums[j];
            else nm[kol++]=nums[i]*nums[j];
            rec(nm,cur+1);
        }
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll nums[4];
    for(int i=0;i<4;i++)
        cin >> nums[i];
    cin >> mas[0] >> mas[1] >> mas[2];
//  sort(&mas[0],&mas[3]);
//  do{
        rec(nums);
//  }while(next_permutation(&mas[0],&mas[3]));
    cout << ans << endl;
    return 0;
}