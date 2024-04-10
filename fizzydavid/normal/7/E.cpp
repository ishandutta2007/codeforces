//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const char opc[4]={'+','-','*','/'};
struct operation
{
    string s;
    int m;
    //f1: +-  f2: */
    bool sus,f1,f2;
    operation *p1,*p2;
    operation(){m=sus=f1=f2=0;p1=p2=NULL;}
};
map<string,operation*>m;
set<string>macro;
int n;
string s;
operation* init(string st)
{
    operation *p=new operation;
    p->s=st;int cnt=0;
    for(int k=0;k<4;k++)
    {
        for(int i=int(st.size()-1);i>=0;i--)
        {
            if(st[i]=='(')cnt++;else if(st[i]==')')cnt--;
            else if(cnt==0&&st[i]==opc[k])
            {
                p->m=i;if(k<2)p->f1=1;else p->f2=1;
                p->p1=init(st.substr(0,i));p->p2=init(st.substr(i+1,int(st.size()-i)));
                if(p->p1->sus||p->p2->sus||k==1&&p->p2->f1||k==2&&(p->p1->f1||p->p2->f1)||k==3&&(p->p1->f1||p->p2->f1||p->p2->f2))p->sus=1;
                if(p->p1->f1||p->p2->f1)p->f1=1;
                if(p->p1->f2||p->p2->f2)p->f2=1;
                break;
            }
        }
        if(p->m!=0)break;
    }
    if(p->m==0)
    {
        if(st[0]=='('&&st[int(st.size()-1)]==')')
        {
            p->p1=init(st.substr(1,int(st.size()-2)));
        }
        if(macro.count(st)>0)
        {
            p->p1=m[st];
            p->f1=p->p1->f1;
            p->f2=p->p1->f2;
            p->sus=p->p1->sus;
        }
        else
        {
            p->f1=p->f2=0;
            if(p->p1!=NULL&&p->p1->sus)p->sus=1;
        }
    }
    return p;
}
string get(char tmp)
{
    string s2;char c;
    s2.clear();
    while(true)
    {
        c=cin.get();
        if(c==tmp)break;
        if(c!=32)s2.PB(c);
    }
    return s2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;string s1,s2;char c;
    for(int i=1;i<=n;i++)
    {
        get('e');get('e');
        cin>>s1;
        s2=get(10);
        m[s1]=init(s2);
        macro.insert(s1);
    }
    string s;
    s=get(10);
    operation *p=init(s);
    if(p->sus)cout<<"Suspicious"<<endl;else cout<<"OK"<<endl;
    return 0;
}