#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
/*
#ifndef ONLINE_JUDGE
int AA=(int)freopen("input.txt","r",stdin);
int BB=(int)freopen("output.txt","w",stdout);
#endif
*/
#define ll long long

using namespace std;

int main()
{
    int T,P[52][52]={0},points[52]={0};
    vector <string> names;
    cin >> T;
    int D[]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int t=0;t<T;t++)
    {
        int n;
        cin >> n;
        char mas1[100]={0};
        cin.getline(mas1,100);
        for(int i=0;i<n;i++)
        {
            char mas[100]={0};
            string s="";
            cin.getline(mas,100);
            s=mas;
            int num=-1;
            for(int j=0;j<names.size();j++)
            {
                if (names[j]==s)
                {
                    num=j;
                    break;
                }
            }
            if (num==-1)
            {
                num=names.size();
                names.push_back(s);
            }
            points[num]+=D[i];
            P[num][i]++;
        }
    }
    int cur=0;
    for(int i=1;i<names.size();i++)
    {
        if (points[i]>points[cur])
        {
            cur=i;
        }
        else
        {
            if (points[i]==points[cur])
            {
                for(int j=0;j<names.size();j++)
                {
                    if (P[i][j]>P[cur][j])
                    {
                        cur=i;
                        break;
                    }
                    if (P[i][j]<P[cur][j])
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << names[cur] << endl;
    int cur1=0;
    for(int i=1;i<names.size();i++)
    {
        if (P[i][0]>P[cur1][0])
        {
            cur1=i;
        }
        else
        {
            if (P[i][0]==P[cur1][0])
            {
                if (points[i]>points[cur1])
                {
                    cur1=i;
                }
                else
                {
                    if (points[i]==points[cur1])
                    {
                        for(int j=1;j<names.size();j++)
                        {
                            if (P[i][j]>P[cur1][j])
                            {
                                cur1=i;
                                break;
                            }
                            if (P[i][j]<P[cur1][j])
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << names[cur1] << endl;
    return 0;
}