/*#include<iostream>
#include<string>
#include<map>

using namespace std;

int n, m, c, ans;
string name;
int num[41];

map <string,int> code;

int main()
{
    cin >> n >> m;

    for(int i=1; i<=n; i++)
    {
        cin >> c;

        if(c==1)
        {
            int Max = 0;
            for(int j=1; j<=m; j++)
            {
                if(Max < num[j]) Max=num[j];
                num[j]=0;
            }
            ans+=Max;
        }
        else
        {
            cin >> name;

            code[name]
        }
    }
}*/

#include<stdio.h>
#include<algorithm>

using namespace std;

int n;
int ans=0, t;
int a[1001];

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a+n);

    for(int i=0; i<=n-i-1; i++)
    {
        if(a[n-i-1]-a[i] > 1) {
            ans += a[n-i-1]-a[i]-2;
        }
        if(n-i-1 -i < 2) t= (a[n-i-1]+a[i])/2;
    }

    for(int i=0; i<=n-i-1; i++)
    {
        if(a[n-i-1]-a[i] > 1) {
            if(a[i]==t)
            {
                t++;
                break;
            }
            if(a[n-i-1]==t)
            {
                t--;
                break;
            }
        }
    }

    printf("%d %d", t, ans);
}