#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#define ll long long

using namespace std;

struct Tov{
    Tov(int a,int b,int c) : a(a), b(b), num(c) {};
    int a,b,num;
};

bool sort1(Tov a,Tov b)
{
    if (a.a<b.a||a.a==b.a&&a.b<b.b) return true;
    return false;
}

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    int T,N;
    cin >> T;
    for(int k=0;k<T;k++)
    {
        cin >> N;
        vector <Tov> v(2*N-1,Tov(0,0,0));
        for(int i=0;i<2*N-1;i++)
        {
            cin >> v[i].a >> v[i].b;
            v[i].num=i;
        }
        sort(v.begin(),v.end(),sort1);
        vector <int> used(2*N-1,0);
        int kol=0,s=0;
        for(int i=1;i<v.size();i++)
        {
            if (v[i-1].b<=v[i].b)
            {
                used[v[i-1].num]=2;
                used[v[i].num]=1;
                kol++;
                i++;
            }
        }
        int t=0;
        while(kol<N)
        {
            if (used[v[t].num]==0)
            {
                s++;
                if (s%2==1)
                {
                    used[v[t].num]=1;
                    kol++;
                }
            }
            t++;
        }
        cout << "YES\n";
        bool f=true;
        for(int i=0;i<used.size();i++)
            if (used[i]==1)
            {
                if (f)
                {
                    cout << i+1;
                    f=false;
                }
                else cout << " " << i+1;
            }
        cout << endl;
    }
    return 0;
}