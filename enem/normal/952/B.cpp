#include <bits/stdc++.h>
using namespace std;

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    set<string> g,b;
    g.insert("cool");
    g.insert("not bad");
    g.insert("don't touch me!");
    g.insert("don't think so");
    g.insert("great!");
    b.insert("don't even");
    b.insert("are you serious?");
    b.insert("go die in a hole");
    b.insert("worse");
    b.insert("terrible");
    b.insert("no way");
    bool f[10]={};
    while(true)
    {
        int x=rng()%10;
        if(f[x]) continue;
        f[x]=true;
        cout<<x<<endl;
        string res;
        getline(cin,res);
        if(g.count(res))
        {
            cout<<"normal"<<endl;
            return 0;
        }
        else if(b.count(res))
        {
            cout<<"grumpy"<<endl;
            return 0;
        }
    }

    return 0;
}