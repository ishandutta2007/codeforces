//2019.1.26 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
inline int read() {
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-')w=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y) {
    x^=y^=x^=y;
}
inline int _max(const res &x,const res &y) {
    return x>y?x:y;
}
inline int _min(const res &x,const res &y) {
    return x<y?x:y;
}
const int N=3e5+10;
namespace MAIN {
    int n,m;
    string str[N],Ans[N],ret,pos[N];
#define pb push_back
    int ans=inf;
    int qaq;
    bool flag;
    string ss[N];
    inline void MAIN(){
        n=read(),m=read();
        for(res i=1;i<=n;i++)cin>>str[i];
        qaq=0;
        for(res i=1;i<=n;i++){
            if(i&1){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(!(i&1)){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(i&1){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(!(i&1)){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(i&1){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(!(i&1)){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[i][j]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[i][j]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];}

        _swap(n,m);
        
//        for(res i=1;i<=n;i++){
//        	for(res j=0;j<m;j++)putchar(str[j+1][i-1]);
//        	puts("");
//        }
        qaq=0;
        for(res i=1;i<=n;i++){
            if(i&1){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];flag=1;}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(!(i&1)){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];flag=1;}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(i&1){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];flag=1;}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(!(i&1)){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];flag=1;}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(i&1){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];flag=1;}

        qaq=0;
        for(res i=1;i<=n;i++){
            if(!(i&1)){
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('A'),ret.pb('T');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('A');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('T'),ret.pb('A');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('T');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
            else {
                ret.clear();
                res QAQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('G'),ret.pb('C');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('G');
                for(res j=0;j<m;j++)QAQ+=(ret[j]!=str[j+1][i-1]);
                pos[i]=ret;
                ret.clear();
                res QWQ=0;
                for(res j=1;j<=m/2;j++)ret.pb('C'),ret.pb('G');
                for(res j=(int)m/2*2+1;j<=m;j++)ret.pb('C');
                for(res j=0;j<m;j++)QWQ+=(ret[j]!=str[j+1][i-1]);
                if(QWQ<QAQ)pos[i]=ret;
                qaq+=_min(QAQ,QWQ);
            }
        }
        if(qaq<ans){ans=qaq;for(res i=1;i<=n;i++)Ans[i]=pos[i];flag=1;}

//		printf("%d\n",ans);
        if(!flag){
            _swap(n,m);
            for(res i=1;i<=n;i++){
                for(res j=1;j<=m;j++)putchar(Ans[i][j-1]);
                puts("");
            }
        }
        else {
            for(res j=1;j<=m;j++){
                for(res i=1;i<=n;i++)putchar(Ans[i][j-1]);
                puts("");
            }
        }
    }
}
int main() {
    MAIN::MAIN();
    return 0;
}