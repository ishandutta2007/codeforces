#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int v[100005]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    ll k,sum=0;
    scanf("%d%I64d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        sum+=v[i];
    }
    if (sum<k)
    {
        printf("-1\n");
        return 0;
    }
    ll num=k/n,cnt=n,lcnt;
    while(k>0&&k>=cnt)
    {
        num=k/cnt;
        lcnt=cnt;
        ll free=0;
        for(int i=0;i<n;i++)
        {
            if (v[i]>0&&v[i]<num) free+=num-v[i];
            if (v[i]>0&&v[i]<=num) cnt--;
            v[i]-=num;
        }
        k=k-num*lcnt+free;
    }
    for(int i=0;i<n;i++)
    {
        if (k==0)
        {
            bool first=true;
            for(int j=i;j<n;j++)
            {
                if (v[j]>0)
                {
                    if (!first) printf(" ");
                    first=false;
                    printf("%d",j+1);
                }
            }
            for(int j=0;j<i;j++)
            {
                if (v[j]>0)
                {
                    if (!first)
                        printf(" ");
                    first=false;
                    printf("%d",j+1);
                }
            }
            printf("\n");
            break;
        }
        if (v[i]>0)
        {
            v[i]--;
            k--;
        }
    }
//  cout << 100000 << endl;
//  for(int i=0;i<100000;i++)
//      cout << rand()*RAND_MAX+rand() << endl;
    return 0;
}