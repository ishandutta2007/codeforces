#include <iostream>
#include <string>

using namespace std;

string brackets;

struct node
{
    int complete;
    int unusedleft;
    int unusedright;
    bool badflag;
    node():
        complete(0),
        unusedleft(0),
        unusedright(0),
        badflag(false)
    {
        //
    }
} seg[2097152];

node combine(node l, node r)
{
    if(l.badflag)
        return r;
    if(r.badflag)
        return l;
    node ret;
    int newpair=min(l.unusedleft, r.unusedright);
    ret.complete=l.complete+r.complete+newpair;
    ret.unusedleft=l.unusedleft+r.unusedleft-newpair;
    ret.unusedright=l.unusedright+r.unusedright-newpair;
    return ret;
}

void initialize(int idx, int begin, int end)
{
    if(begin==end)
    {
        seg[idx].complete=0;
        if(brackets[begin-1]=='(')
            seg[idx].unusedleft=1;
        else
            seg[idx].unusedright=1;
    }
    else
    {
        initialize(idx*2, begin, (begin+end)/2);
        initialize(idx*2+1, (begin+end)/2+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

node query(int idx, int begin, int end, int l, int r)
{
    if(end<l || r<begin)
    {
        node n;
        n.badflag=true;
        return n;
    }
    if(l<=begin && end<=r)
        return seg[idx];
    return combine(query(idx*2, begin, (begin+end)/2, l, r),
                   query(idx*2+1, (begin+end)/2+1, end, l, r));
}

int main()
{
    //freopen("inb.txt", "r", stdin);
    cin>>brackets;
    initialize(1, 1, brackets.length());
    int Q, l, r;
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>l>>r;
        cout<<query(1, 1, brackets.length(), l, r).complete*2<<'\n';
    }

    return 0;
}