#include <bits/stdc++.h>

using namespace std;

int M, S;
string dpm[101][901];
string dpM[101][901];

string minimum(int len, int sum)
{
    if(!dpm[len][sum].empty())
        return dpm[len][sum];
    if(sum<0)
        return dpm[len][sum]="-1";
    if(len==1)
    {
        if(sum<=9)
            return dpm[len][sum]=string(1, sum+'0');
        return dpm[len][sum]="-1";
    }
    for(int i=(len==M)?1:0; i<=9; i++)
    {
        string s=minimum(len-1, sum-i);
        if(s!="-1")
            return dpm[len][sum]=string(1, i+'0')+s;
    }
    return dpm[len][sum]="-1";
}

string maximum(int len, int sum)
{
    if(!dpM[len][sum].empty())
        return dpM[len][sum];
    if(sum<0)
        return dpM[len][sum]="-1";
    if(len==1)
    {
        if(sum<=9)
            return dpM[len][sum]=string(1, sum+'0');
        return dpM[len][sum]="-1";
    }
    for(int i=9; i>=(len==M)?1:0; i--)
    {
        string s=maximum(len-1, sum-i);
        if(s!="-1")
            return dpM[len][sum]=string(1, i+'0')+s;
    }
    return dpM[len][sum]="-1";
}

int main()
{
    scanf("%d%d", &M, &S);
    cout<<minimum(M, S)<<" ";
    cout<<maximum(M, S)<<"\n";
    return 0;
}