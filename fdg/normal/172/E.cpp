#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#include <sstream>

#define ll long long

using namespace std;

struct tree{
    tree() : par(NULL), val(0) { next.clear(); };
    map <int,tree *> next;
    tree * par;
    int val;
    void setParent(tree * p) {
        par=p;
    }
};

tree * moveDown(tree * root,int n) {
    tree * ret=NULL;
    if (root->next.count(n)) {
        ret=root->next[n];
    } else {
        ret=new tree();
        ret->setParent(root);
        root->next[n]=ret;
    }
    ret->val++;
    return ret;
}

tree * moveUp(tree * root) {
    return root->par;
}

char line[1000003];
char tmp[5002];
map <string,int> f;

vector <int> v;

int go(tree * root,int what) {
    int ans=0;
    for(map <int,tree*>::iterator it=root->next.begin();it!=root->next.end();++it) {
        if (it->first==what) ans+=it->second->val+go(it->second,what);
        else ans+=go(it->second,what);
    }
    return ans;
}

int calc(tree * root,int ind = 0) {
    if (ind+1==v.size()) {
        return go(root,v[ind]);
    }
    int ans=0;
    for(map <int,tree*>::iterator it=root->next.begin();it!=root->next.end();++it) {
        if (it->first==v[ind]) ans+=calc(it->second,ind+1);
        else ans+=calc(it->second,ind);
    }
    return ans;
}

void out(tree * root,int par = -1) {
    for(map <int,tree*>::iterator it=root->next.begin();it!=root->next.end();++it) {
        out(it->second,it->first);
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    tree * root=new tree(),*root1=root;
    char str[25]={0};
    gets(line);
    int l=strlen(line),tot=0;
    map <string,int>::iterator it;
    for(int i=0;i<l;++i) {
        if (line[i]=='<') {
            int type=0,len=0;
            if (line[i+1]=='/') type=1;
            for(i=i+1+(type==1);i<l;++i) {
                if (line[i]=='/') type=2;
                else if (line[i]=='>') break;
                else str[len++]=line[i];
            }
            int num=0; str[len]='\0';
            it=f.find(string(str));
            if (it!=f.end()) num=it->second;
            else f[string(str)]=num=tot++;
            if (type==0) {
                root=moveDown(root,num);
            } else if (type==1) {
                root=moveUp(root);
            } else {
                moveDown(root,num);
            }
        }
    }
//  out(root1);
    int q;
    scanf("%d\n",&q);
    while(q--) {
        gets(tmp);
        istringstream ss(tmp);
        string s; bool ok=true;
        v.clear();
        while(ss>>s) {
            it=f.find(s);
            if (it!=f.end()) {
                v.push_back(it->second);
            } else {
                ok=false;
                break;
            }
        }
        if (ok)
            printf("%d\n",calc(root1));
        else printf("0\n");
    }
    return 0;
}