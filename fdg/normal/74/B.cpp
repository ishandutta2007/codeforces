#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define ll long long

using namespace std;


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,r,k,cur=1,time=0;
    string str;
    cin >> n >> r >> k >> str >> str;
    if (str[0]=='h') cur=-1;
    char c;
    while(cin >> c)
    {
        time++;
        if (c=='0')
        {
            int next=k;
            if (k+cur>n||k+cur<1) cur*=-1;
            next+=cur;
            int v1=r,v2=max(1,r-1),v3=min(n,r+1);
            if (abs(v1-(k))>abs(v2-k)&&abs(v1-(k))>abs(v3-k)) r=v1;
            else if (abs(v2-(k))>abs(v3-k)) r=v2;
            else r=v3;
            k=next;
            if (k==r)
            {
                cout << "Controller " << time << endl;
                return 0;
            }
        }
        else
        {
            if (k+cur>n||k+cur<1) cur*=-1;
            k+=cur;
            if (k==1) r=n;
            else if (k==n) r=1;
            else if (cur==1) r=1;
            else r=n;
            if (k==r)
            {
                cout << "Controller " << time << endl;
                return 0;
            }
        }
    }
    cout << "Stowaway\n";
    return 0;
}