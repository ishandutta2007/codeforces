#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#define N 300020
#define S 26
using namespace std;

class ACAM
{
public:
    class Node
    {
    public:
        Node *s[S];
        Node *f;
        int g;
        bool v;

        Node(Node *r = NULL)
        {
            int i;

            for(i = 0; i < S; i ++)
                s[i] = r;
            f = r;
            g = 0;
            v = false;

            return;
        }
    };

    Node *r;
    queue<Node *> q;

    ACAM(void)
    {
        r = new Node();
        *r = Node(r);

        return;
    }

    inline int ID(char c)
    {
        return c - 97;
    }

    void InsertACAM(string &s)
    {
        int i;
        Node *p;

        for(i = 0, p = r; i < (signed)s.size(); i ++)
        {
            if(p -> s[ID(s[i])] == r)
                p -> s[ID(s[i])] = new Node(r);
            p = p -> s[ID(s[i])];
        }
        p -> v = true;

        return;
    }

    void InitACAM(void)
    {
        int i;
        Node *s, *t;

        for(i = 0; i < S; i ++)
            if(r -> s[i] != r)
            {
                r -> s[i] -> g = r -> s[i] -> v;
                q.push(r -> s[i]);
            }

        for(; !q.empty(); q.pop())
        {
            s = q.front();
            for(i = 0; i < S; i ++)
                if(s -> s[i] != r)
                {
                    t = s -> s[i];
                    t -> f = s -> f;
                    while(t -> f != r && t -> f -> s[i] == r)
                        t -> f = t -> f -> f;

                    t -> f = t -> f -> s[i];
                    t -> g = t -> f -> g + t -> v;
                    q.push(t);
                }
                else
                    s -> s[i] = s -> f -> s[i];
        }

        return;
    }

    long long SumACAM(string &s)
    {
        int i;
        Node *p;
        long long o;

        for(i = o = 0, p = r; i < (signed)s.size(); i ++)
        {
            p = p -> s[ID(s[i])];
            o += p -> g;
        }

        return o;
    }
};

class Group
{
public:
    vector<pair<vector<string>, ACAM> > f;
    pair<vector<string>, ACAM> t;

    void InsertGroup(string &s)
    {
        int i, k;

        t.first.clear();
        t.first.push_back(s);
        for(k = 1; !f.empty() && k == (signed)f.back().first.size(); f.pop_back())
        {
            k <<= 1;
            for(i = 0; i < (signed)f.back().first.size(); i ++)
                t.first.push_back(f.back().first.at(i));
        }

        t.second = ACAM();
        for(i = 0; i < k; i ++)
            t.second.InsertACAM(t.first.at(i));
        t.second.InitACAM();
        f.push_back(t);

        return;
    }

    long long SumGroup(string &s)
    {
        int i;
        long long o;

        for(i = o = 0; i < (signed)f.size(); i ++)
            o += f.at(i).second.SumACAM(s);

        return o;
    }
};

string s;
Group f, g;

int main(void)
{
    int m, t;

    ios::sync_with_stdio(false);
    cin >> m;
    while(m --)
    {
        cin >> t >> s;
        if(t == 1)
            f.InsertGroup(s);
        else if(t == 2)
            g.InsertGroup(s);
        else
        {
            cout << f.SumGroup(s) - g.SumGroup(s) << endl;
            cout.flush();
        }
    }

    return 0;
}