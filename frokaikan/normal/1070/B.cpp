#include <bits/stdc++.h>
#define FF first
#define SS second
const int maxN = 2e5+3;
int N;
typedef unsigned int uint;
struct ip
{
    uint addr;
    int fx; // 0~32
    bool type; // 0->black 1->white
    ip(uint _a=0U,int _f=0,bool _t=false):addr(_a),fx(_f),type(_t) {}
};
ip ipin[maxN],ipout[maxN];
int ipcnt = 0;
std::istream& operator>> (std::istream& is, ip& i)
{
    char tmp_ip[30];
    is >> tmp_ip;
    int tmp_sz = std::strlen(tmp_ip);
    if (tmp_ip[0] == '-') i.type = false;
    else i.type = true;
    i.addr = 0U;
    int tmp, pos = 1;
    tmp = 0;
    while (tmp_ip[pos] != '.')
    {
        tmp = tmp*10 + (tmp_ip[pos]-'0');
        ++pos;
    }
    tmp <<= 24;
    i.addr += tmp;
    ++pos;
    tmp = 0;
    while (tmp_ip[pos] != '.')
    {
        tmp = tmp*10 + (tmp_ip[pos]-'0');
        ++pos;
    }
    tmp <<= 16;
    i.addr += tmp;
    ++pos;
    tmp = 0;
    while (tmp_ip[pos] != '.')
    {
        tmp = tmp*10 + (tmp_ip[pos]-'0');
        ++pos;
    }
    tmp <<= 8;
    i.addr += tmp;
    ++pos;
    tmp = 0;
    while (tmp_ip[pos] != '/' && tmp_ip[pos] != '\0')
    {
        tmp = tmp*10 + (tmp_ip[pos]-'0');
        ++pos;
    }
    i.addr += tmp;
    if (pos == tmp_sz)
    {
        i.fx = 32;
        return is;
    }
    ++pos;
    tmp = 0;
    while (tmp_ip[pos] != '\0')
    {
        tmp = tmp*10 + (tmp_ip[pos]-'0');
        ++pos;
    }
    i.fx = tmp;
    return is;
}
std::ostream& operator<< (std::ostream& os, const ip& i)
{
    os << ((i.addr>>24)&255U) << '.' << ((i.addr>>16)&255U) << '.' << ((i.addr>>8)&255U) << '.' << (i.addr&255U) << '/' << i.fx;
    return os;
}
struct Trie
{
    bool n;
    Trie *ch[2];
    int type; // 0->black 1->white 2->unknown
    Trie(bool _n=false):n(_n),type(2) {ch[0] = ch[1] = nullptr;}
};
Trie *root = new Trie ();
bool global_flag = true;
void add(const ip& IP)
{
    Trie *now = root;
    for (int i=0;i<IP.fx;++i)
    {
        bool it = (IP.addr>>(31-i))&1U;
        if (now->ch[it] == nullptr) now->ch[it] = new Trie (it);
        now = now->ch[it];
    }
    if (now->type != 2 && now->type != IP.type) global_flag = false;
    now->type = IP.type;
}
bool check(Trie* now, int type)
{
    if (now->type != 2 && type != 2 && now->type != type) return false;
    if (now->ch[0] && !check(now->ch[0], std::min(type, now->type))) return false;
    if (now->ch[1] && !check(now->ch[1], std::min(type, now->type))) return false;
    return true;
}
void change(Trie *now)
{
    if (now->ch[0])
    {
        change(now->ch[0]);
        if (now->ch[0]->type == 1) now->type = 1;
    }
    if (now->ch[1])
    {
        change(now->ch[1]);
        if (now->ch[1]->type == 1) now->type = 1;
    }
}
void get(Trie *now, uint addr, int fx)
{
    if (now->type != 1)
    {
        ipout[ipcnt++] = {addr, fx};
        return;
    }
    if (now->ch[0]) get(now->ch[0], addr,               fx+1);
    if (now->ch[1]) get(now->ch[1], addr|(1U<<(31-fx)), fx+1);
}
int main()
{
    std::cin >> N;
    for (int i=0;i<N;++i)
    {
        std::cin >> ipin[i];
        add(ipin[i]);
    }
    if (!global_flag || !check(root, root->type)) std::cout << "-1\n";
    else
    {
        change(root);
        get(root, 0U, 0);
        std::cout << ipcnt << "\n";
        for (int i=0;i<ipcnt;++i) std::cout << ipout[i] << "\n";
    }
}