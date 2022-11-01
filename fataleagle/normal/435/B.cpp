#include <bits/stdc++.h>

using namespace std;

int K;
char num[20];
set<pair<pair<int, int>, pair<int, int>>> s;

int main()
{
    //freopen("in.txt", "r", stdin);
    int N=0;
    while((num[N]=getchar())>='0')
        N++;
    num[N]='\0';
    scanf("%d", &K);
    for(int i=0; i<N; i++)
    {
        pair<char, int> maxi=make_pair(num[i], 0);
        for(int j=i+1; j<N; j++)
            if(j-i<=K)
                maxi=max(maxi, make_pair(num[j], i-j));
        if(maxi.second)
        {
            K+=maxi.second;
            for(int j=-maxi.second-1; j>=0; j--)
                swap(num[i+j], num[i+j+1]);
        }
    }
    for(int i=0; i<N; i++)
    {
        int j=i;
        while(j>0 && num[j]>num[j-1] && K>0)
        {
            swap(num[j], num[j-1]);
            j--;
            K--;
        }
    }
    puts(num);
    return 0;
}