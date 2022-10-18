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

int calc(string str)
{
    if (str=="S") return 0;
    if (str=="M") return 1;
    if (str=="L") return 2;
    if (str=="XL") return 3;
    if (str=="XXL") return 4;
}
string ret(int a)
{
    if (a==0) return "S";
    if (a==1) return "M";
    if (a==2) return "L";
    if (a==3) return "XL";
    return "XXL";
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,s,m,l,xl,xxl,k,a[5];
    string str;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> k;
    for(int i=0;i<k;i++)
    {
        cin >> str;
        int best=-1,cur=calc(str);
        for(int j=0;j<5;j++)
        {
            if (a[j]==0) continue;
            if (best==-1)
            {
                best=j;
                continue;
            }
            if (abs(cur-best)>=abs(cur-j)) best=j;
        }
        a[best]--;
        cout << ret(best) << endl;
    }
    return 0;
}