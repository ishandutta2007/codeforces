#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define double long double

const double Pi=3.1415926535897932384626;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int x1,y1,x2,y2,ans=0;
    char a;
    cin >> a >> y1;
    x1=a-'a'+1;
    cin >> a >> y2;
    x2=a-'a'+1;
//  cout << x2 << " " << y2 << endl;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            bool poss=true;
            if (i==x1&&j==y1||i==x2&&j==y2) continue;
            if (x1==i||y1==j) poss=false;
            if (labs(x1-i)==2&&labs(y1-j)==1||labs(x1-i)==1&&labs(y1-j)==2) poss=false;
            if (labs(x2-i)==2&&labs(y2-j)==1||labs(x2-i)==1&&labs(y2-j)==2) poss=false;
            ans+=poss;
        }
    }
    cout << ans << endl;
    return 0;
}