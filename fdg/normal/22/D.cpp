#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

struct Point{
    Point(int a,int b,int c) : x(a), num(b), type(c) {};
    int x,num,type;
};

bool operator <(Point a,Point b)
{
    if (a.x<b.x) return true;
    if (a.x>b.x) return false;
    if (a.type==-1&&b.type==1) return true;
    if (b.type==-1&&a.type==1) return false;
    return false;
}

int main()
{
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");
    int n;
    cin >> n;
    vector <int> l(n,0),r(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> l[i] >> r[i];
        if (l[i]>r[i]) swap(l[i],r[i]);
    }
    vector <Point> p;
    for(int i=0;i<n;i++)
    {
        p.push_back(Point(l[i],i,-1));
        p.push_back(Point(r[i],i,1));
    }
    sort(p.begin(),p.end());
    int curs=0;
    bool used[1001]={0};
    vector <int> points,cur;
    for(int i=0;i<p.size();i++)
    {
        if (p[i].type==1&&(!used[p[i].num]))
        {
            if (curs!=0) points.push_back(p[i].x);
            curs=0;
            for(int j=0;j<cur.size();j++)
                used[cur[j]]=true;
            cur.clear();
        }
        else
        {
            if (!used[p[i].num])
            {
//              used[p[i].num]=true;
                cur.push_back(p[i].num);
                curs--;
            }
        }
    }
    cout << points.size() << endl;
    for(int i=0;i<points.size();i++)
    {
        if (i==0) cout << points[i];
        else cout << " " << points[i];
    }
    cout << endl;
    return 0;
}