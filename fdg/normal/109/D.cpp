#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>
#include <set>

#define ll long long

using namespace std;

enum Color{RED = 0,BLACK = 1};

template <class T1,class T2>
struct RedBlackTree{
    RedBlackTree() : parent(NULL), left(NULL), right(NULL), color(BLACK), key(0), value(0) {};
    RedBlackTree(T1 _key,T2 _value) : parent(NULL), left(NULL), right(NULL), color(BLACK), key(_key), value(_value) {};
    T1 key; T2 value;
    Color color;
    RedBlackTree * parent, * left, * right;
    RedBlackTree * operator = (const T2 & _value) {
        value=_value;
        return this;
    };
//  RedBlackTree * insert(pair <T1,T2> value);
};

/*template<class T1,class T2>
RedBlackTree<T1,T2> * operator = (RedBlackTree<T1,T2> * y) {
//  x->value=value;
    return x;
};*/

/*template <class T1,class T2>
RedBlackTree<T1,T2> * RedBlackTree<T1,T2>::insert(pair <T1,T2> value) {
//  cout << key << endl;
    return NULL;
};*/

template <class T1,class T2>
void CopyData(RedBlackTree<T1,T2> * & z,RedBlackTree<T1,T2> * & y) {
    z->value=y->value;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Find(RedBlackTree<T1,T2> * x,T1 k) {
    while(x!=NULL&&k!=x->key) {
        if (k<x->key) x=x->left;
        else x=x->right;
    }
    return x;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Minimum(RedBlackTree<T1,T2> * root) {
    if (root==NULL) return NULL;
    while(root->left!=NULL) root=root->left;
    return root;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Maximum(RedBlackTree<T1,T2> * root) {
    if (root==NULL) return NULL;
    while(root->right!=NULL) root=root->right;
    return root;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Successor(RedBlackTree<T1,T2> * root) {
    if (root==NULL) return NULL;
    if (root->right!=NULL)
        return Minimum(root->right);
    RedBlackTree<T1,T2> * y=root->parent;
    while(y!=NULL&&root==y->right) {
        root=y; y=y->parent;
    }
    return y;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Predecessor(RedBlackTree<T1,T2> * root) {
    if (root==NULL) return NULL;
    if (root->left!=NULL)
        return Maximum(root->left);
    RedBlackTree<T1,T2> * y=root->parent;
    while(y!=NULL&&root==y->left) {
        root=y; y=y->parent;
    }
    return y;
}

template <class T1,class T2>
void LeftRotate(RedBlackTree<T1,T2> * & root,RedBlackTree<T1,T2> * x) {
    if (x->right==NULL) return;
    RedBlackTree <T1,T2> * y=x->right;
    x->right=y->left;
    if (y->left!=NULL) y->left->parent=x;
    y->parent=x->parent;
    if (x->parent==NULL) root=y;
    else {
        if (x==x->parent->left) x->parent->left=y;
        else x->parent->right=y;
    }
    y->left=x;
    x->parent=y;
}

template <class T1,class T2>
void RightRotate(RedBlackTree<T1,T2> * & root,RedBlackTree<T1,T2> * y) {
    if (y->left==NULL) return;
    RedBlackTree <T1,T2> * x=y->left;
    y->left=x->right;
    if (x->right!=NULL) x->right->parent=y;
    x->parent=y->parent;
    if (y->parent==NULL) root=x;
    else {
        if (y==y->parent->left) y->parent->left=x;
        else y->parent->right=x;
    }
    x->right=y;
    y->parent=x;
}

template<class T1,class T2>
void InsertFixup(RedBlackTree<T1,T2> * & root,RedBlackTree<T1,T2> * z) {
    while(z->parent!=NULL&&z->parent->color==RED) {
        if (z->parent==z->parent->parent->left) {
            RedBlackTree<T1,T2> * y=z->parent->parent->right;
            if (y!=NULL&&y->color==RED) {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            } else {
                if(z==z->parent->right) {
                    z=z->parent;
                    LeftRotate(root,z);
                }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                RightRotate(root,z->parent->parent);
            }
        } else {
            RedBlackTree<T1,T2> * y=z->parent->parent->left;
            if (y!=NULL&&y->color==RED) {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;
                z=z->parent->parent;
            } else {
                if(z==z->parent->left) {
                    z=z->parent;
                    RightRotate(root,z);
                }
                z->parent->color=BLACK;
                z->parent->parent->color=RED;
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    root->color=BLACK;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Insert(RedBlackTree<T1,T2> * & root,T1 key,T2 value) {
    RedBlackTree<T1,T2> * z=new RedBlackTree<T1,T2>(key,value);
    RedBlackTree<T1,T2> * y=NULL, * x=root;
    while(x!=NULL) {
        y=x;
        if (z->key<x->key) x=x->left;
        else x=x->right;
    }
    z->parent=y;
    if (y==NULL) root=z;
    else {
        if (z->key<y->key) y->left=z;
        else y->right=z;
    }
    z->left=NULL;
    z->right=NULL;
    z->color=RED;
    InsertFixup(root,z);
    return z;
}

template <class T1,class T2>
void DeleteFixup(RedBlackTree<T1,T2> * & root,RedBlackTree<T1,T2> * x) {
    while(x!=NULL&&x!=root&&x->color==BLACK) {
        if (x==x->parent->left) {
            RedBlackTree<T1,T2> * w=x->parent->right;
            if (w!=NULL&&w->color==RED) {
                w->color=BLACK;
                x->parent->color=RED;
                LeftRotate(root,x->parent);
                w=x->parent->right;
            }
            if (w->left->color==BLACK&&w->right->color==BLACK) {
                w->color=RED;
                x=x->parent;
            } else {
                if (w->right->color==BLACK) {
                    w->left->color=BLACK;
                    w->color=RED;
                    RightRotate(root,w);
                    w=x->parent->right;
                }
                w->color=x->parent->color;
                x->parent->color=BLACK;
                w->right->color=BLACK;
                LeftRotate(root,x->parent);
                x=root;
            }
        } else {
            RedBlackTree<T1,T2> * w=x->parent->left;
            if (w!=NULL&&w->color==RED) {
                w->color=BLACK;
                x->parent->color=RED;
                RightRotate(root,x->parent);
                w=x->parent->left;
            }
            if (w->left->color==BLACK&&w->right->color==BLACK) {
                w->color=RED;
                x=x->parent;
            } else {
                if (w->left->color==BLACK) {
                    w->right->color=BLACK;
                    w->color=RED;
                    LeftRotate(root,w);
                    w=x->parent->left;
                }
                w->color=x->parent->color;
                x->parent->color=BLACK;
                w->left->color=BLACK;
                RightRotate(root,x->parent);
                x=root;
            }
        }
    }
    if (x!=NULL)
        x->color=BLACK;
}

template <class T1,class T2>
RedBlackTree<T1,T2> * Delete(RedBlackTree<T1,T2> * & root,RedBlackTree<T1,T2> * z) {
    RedBlackTree <T1,T2> * y, * x;
    if (z->left==NULL||z->right==NULL) y=z;
    else y=Successor(z);
    if (y->left!=NULL) x=y->left;
    else x=y->right;
    if (x!=NULL) x->parent=y->parent;
    if (y->parent==NULL) root=x;
    else if (y==y->parent->left) y->parent->left=x;
    else y->parent->right=x;
    if (y!=z) {
        z->key=y->key;
        CopyData(z,y);
    }
    if (y->color==BLACK) DeleteFixup(root,x);
    return y;
}

template <class T1,class T2>
void Clear(RedBlackTree<T1,T2> * & root) {
    if (root==NULL) return;
    Clear(root->left);
    Clear(root->right);
    delete root;
    root=NULL;
}

template <class T1,class T2>
void Output(RedBlackTree<T1,T2> * root,int cnt = 0) {
    if (root==NULL) return;
    Output(root->right,cnt+1);
    for(int i=0;i<cnt;++i)
        cout << "   ";
    cout << "(" << root->key << ";" << root->color << ";" << root->value << ")\n";
    Output(root->left,cnt+1);
}

template <class T1,class T2>
struct myMap{
    myMap() : root(NULL) {};
    RedBlackTree<T1,T2> * root;
    RedBlackTree<T1,T2> * count(const T1 & key);
    T2 & operator[](const T1 & key);
    void clear() {Clear(root);};
    RedBlackTree<T1,T2> * insert(const pair <T1,T2> & value);
    RedBlackTree<T1,T2> * begin();
    RedBlackTree<T1,T2> * end() {return Maximum(root);};
    struct iterator {
        iterator() : node(NULL) {};
        iterator(RedBlackTree<T1,T2> * _node) : node(_node) {};
        RedBlackTree<T1,T2> * node;
        iterator & operator ++() {
            node=Successor(node);
            return *this;
        }
        iterator operator ++(int) {
            RedBlackTree<T1,T2> * tmp=node;
            node=Successor(node);
            return tmp;
        }
        iterator & operator --() {
            node=Predecessor(node);
            return *this;
        }
        iterator operator --(int) {
            RedBlackTree<T1,T2> * tmp=node;
            node=Predecessor(node);
            return tmp;
        }
        bool operator !=(const iterator & it) {
            return it.node!=node;
        }
        RedBlackTree<T1,T2> * & operator ->() {
            return node;
        }
    };
};

template<class T1, class T2>
RedBlackTree<T1,T2> * myMap<T1,T2>::begin() {
    return Minimum(root);
}

template <class T1,class T2>
RedBlackTree<T1,T2> * myMap<T1,T2>::count(const T1 & key) {
    return Find(root,key);
}

template <class T1,class T2>
RedBlackTree<T1,T2> * myMap<T1,T2>::insert(const pair <T1,T2> & value) {
//  RedBlackTree<T1,T2> * tmp=new RedBlackTree<T1,T2>(value.first,value.second);
    return Insert(root,value.first,value.second);
}

template <class T1,class T2>
T2 & myMap<T1,T2>::operator[](const T1 & key) {
    RedBlackTree<T1,T2> * ret=count(key);
    if (ret==NULL) ret=Insert(root,key,T2());
    return ret->value;
}

int nums[100005],n,v[100005],A[100005];
myMap <int,int> f,s;

bool isOk(int a)
{
    if (a==0) return false;
    while(a)
    {
        if (a%10!=4&&a%10!=7) return false;
        a/=10;
    }
    return true;
}

vector <int> x,y;

pair <int,int> vv[100005];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
        A[i]=v[i]=nums[i];
        vv[i]=make_pair(nums[i],i);
    }
    sort(v,v+n);
    int pos=-1,happy;
    for(int i=0;i<n;i++)
    {
        if (isOk(nums[i]))
        {
            pos=i;
            happy=nums[i];
            break;
        }
    }
    if (pos!=-1)
    {
        sort(vv,vv+n);
        for(int i=0;i<n;i++)
            nums[vv[i].second]=i+1;
        for(int i=0;i<n;i++)
        {
            v[i]=nums[i];
            f[v[i]]=i;
        }
        happy=v[pos];
        sort(v,v+n);
        for(int i=0;i<n;i++)
            s[i]=v[i];
        for(int i=0;i<n;i++)
        {
            int a=f[happy],b=i,pa=a,pb=b;
            if (a!=b)
            {
                swap(nums[a],nums[b]);
                swap(A[a],A[b]);
                x.push_back(a);
                y.push_back(b);
                f[nums[a]]=a; f[nums[b]]=b;
            }
            a=f[happy],b=f[s[i]];
            if (a!=b)
            {
                swap(nums[a],nums[b]);
                swap(A[a],A[b]);
                x.push_back(a);
                y.push_back(b);
                f[nums[a]]=a; f[nums[b]]=b;
            }
            if (pa!=pb&&min(pa,pb)==min(a,b)&&max(pa,pb)==max(a,b))
            {
                x.pop_back();
                y.pop_back();
                x.pop_back();
                y.pop_back();
            }
        }
    //  for(int i=0;i<n;i++)
    //      cout << nums[i] << "    ";
    //  cout << endl;
        printf("%d\n",x.size());
        for(int i=0;i<x.size();i++)
            printf("%d %d\n",x[i]+1,y[i]+1);
    }
    else
    {
        for(int i=1;i<n;i++)
            if (A[i-1]>A[i])
            {
                cout << -1 << endl;
                return 0;
            }
        cout << 0 << endl;
    }
//  for(int i=1;i<n;i++)
//      if (A[i-1]>A[i]) return -1;
//  if (x.size()>2*n) for(;;);
//  cout << 100 << endl << 4 << endl;
//  for(int i=1;i<100;i++)
//      cout << rand() << " ";
    return 0;
}