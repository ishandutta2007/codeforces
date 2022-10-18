#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

int x[100005]={0},y[100005]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,minx=3000000,miny=3000000,maxx=0,maxy=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]+=1000002;
        y[i]+=1000002;
        if (x[i]>maxx) maxx=x[i];
        if (x[i]<minx) minx=x[i];
        if (y[i]>maxy) maxy=y[i];
        if (y[i]<miny) miny=y[i];
    }
    maxx++; maxy++;
    minx--; miny--;
    int rd=-100000000;
    for(int i=0;i<n;i++)
        if (x[i]-y[i]>rd) rd=x[i]-y[i];
    rd++;
//  cout << rd << endl;
    int ld=100000000;
    for(int i=0;i<n;i++)
        if (x[i]+y[i]<ld) ld=x[i]+y[i];
    ld--;
//  cout << ld << endl;
    int lu=-100000000;
    for(int i=0;i<n;i++)
        if (y[i]-x[i]>lu) lu=y[i]-x[i];
    lu++;
//  cout << lu << endl;
    int ru=-100000000;
    for(int i=0;i<n;i++)
        if (x[i]+y[i]>ru) ru=x[i]+y[i];
    ru++;
//  cout << ru << endl;
    int ans=(maxx-minx+maxy-miny)*2;
    int tmp_x=ld-miny;
    ans-=tmp_x-minx;
    tmp_x=rd+miny;
    ans-=maxx-tmp_x;
    tmp_x=maxy-lu;
    ans-=tmp_x-minx;
    tmp_x=ru-maxy;
    ans-=(maxx-tmp_x);
    cout << ans << endl;
    return 0;
}