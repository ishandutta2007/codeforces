#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<int MAXA>
struct LiChaoTree{
    struct Line{
        int m,c;
        Line(){}
        Line(int m,int c) : m(m), c(c) {}
        int evaluate(int x){
            return m*x + c;
        }
    };
    struct Node{
        Line top;
        int left=-1, right=-1;
        Node() {}
        Node(int m, int c) : top(Line(m,c)) {}
        Node (Line curr) : top(curr) {}
        int evaluate(int x){
            return top.evaluate(x);
        }
    };
    vector<Line> lines;
    vector<Node> Tree;
    const int INF = 1e9 + 7;
    LiChaoTree(){
        Tree.emplace_back(0,INF);
    }
    void addline(int m,int c){
        addline(Line(m,c),0,MAXA+1,0);
        lines.push_back(Line(m,c));
    }
    void addline(Line toadd,int l,int r,int idx){
        int mid = (l+r)/2;
        Line& top = Tree[idx].top;
        if(top.evaluate(mid) > toadd.evaluate(mid)){
            swap(top, toadd);
        }
        if(r-l <= 1) return;
        if(top.evaluate(l) > toadd.evaluate(l)){
            if(Tree[idx].left == -1){
                Tree[idx].left = Tree.size();
                Tree.emplace_back(top);
            }
            addline(toadd,l,mid,Tree[idx].left);
        }
        else{
            if(Tree[idx].right == -1){
                Tree[idx].right = Tree.size();
                Tree.emplace_back(top);
            }
            addline(toadd,mid,r,Tree[idx].right);
        }
    }
    int query(int x){
        return min(Tree[0].evaluate(x), query(x,0,MAXA+1,0));// * (maximum ? 1 : -1);
    }
    int query(int x,int l,int r,int idx){
        if(idx==-1) return INF;
        if(x<l || x>=r) return Tree[idx].evaluate(x);
        if(r-l <= 1) return Tree[idx].evaluate(x);
        int mid = (l+r)/2;
        return min({Tree[idx].evaluate(x), query(x,l,mid,Tree[idx].left), query(x,mid,r,Tree[idx].right)});
    }
};
const int MAXA = 1e5;
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    cin>>seq;
    vector<int> psum(n+1);
    for(int i=1;i<=n;i++) psum[i] = psum[i-1] + seq[i-1];
    int m;
    cin>>m;
    vector<LiChaoTree<MAXA>> segtree(n<<1);
    for(int i=0;i<n;i++){
        segtree[n+i].addline(-seq[i], (i+1)*seq[i] - psum[i+1]);
    }
    for(int i=n-1;i>0;--i){
        for(const auto &l : segtree[2*i].lines){
            segtree[i].addline(l.m,l.c);
        }
        for(const auto &l : segtree[2*i + 1].lines){
            segtree[i].addline(l.m,l.c);
        }
    }
    auto query = [&](int l,int r,int val){
        l+=n;
        r+=n+1;
        int ans = 1e9 + 7;
        while(l < r){
            if(l&1){
                ans = min(ans, segtree[l].query(val));
                ++l;
            }
            if(r&1){
                --r;
                ans = min(ans, segtree[r].query(val));
            }
            l>>=1;
            r>>=1;
        }
        return ans;
    };
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        cout<<psum[y] + query(y-x, y-1, y-x)<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}