#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

#ifndef ONLINE_JUDGE

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);
FILE *file_in = fopen("input.txt", "rt");
FILE *file_out = fopen("output.txt", "wt");

#else

#define fin cin
#define fout cout
#define file_in stdin
#define file_out stdout

#endif

typedef pair< int, int > TEntry;

struct TNode {
    TEntry key;
    int height;
    int maxy;
    TNode *left, *right;
    TNode(TEntry &_key)
        : key(_key)
        , height(rand() * RAND_MAX + rand())
        , maxy(_key.second)
        , left(NULL)
        , right(NULL)
    {
    }
};

void relax(TNode *node) {
    if (!node) {
        return;
    }

    node->maxy = node->key.second;
    if (node->left) {
        node->maxy = max(node->maxy, node->left->maxy);
    }
    if (node->right) {
        node->maxy = max(node->maxy, node->right->maxy);
    }
}

void split(TNode *root, TNode **left, TNode **right, TEntry &key) {
    if (!root) {
        *left = *right = NULL;
        return;
    }
    
    if (root->key <= key) {
        split(root->right, left, right, key);
        root->right = *left;
        relax(root);
        *left = root;
    } else {
        split(root->left, left, right, key);
        root->left = *right;
        relax(root);
        *right = root;
    }
}

TNode *merge(TNode *left, TNode *right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }

    if (left->height > right->height) {
        left->right = merge(left->right, right);
        relax(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        relax(right);
        return right;
    }
}

TNode *insert(TNode *root, TNode *newNode) {
    if (!root) {
        return newNode;
    }
    if (root->height > newNode->height) {
        if (root->key < newNode->key) {
            root->right = insert(root->right, newNode);
        } else {
            root->left = insert(root->left, newNode);
        }
        relax(root);
        return root;
    } else {
        split(root, &newNode->left, &newNode->right, newNode->key);
        relax(newNode);
        return newNode;
    }
}

TEntry prev(TEntry &entry) {
    return make_pair(entry.first, entry.second - 1);
}

TNode *remove(TNode *root, TEntry &entry) {
    if (root->key == entry) {
        return merge(root->left, root->right);
    }
    if (root->key < entry) {
        root->right = remove(root->right, entry);
    } else {
        root->left = remove(root->left, entry);
    }
    relax(root);
    return root;
}

TNode *leftmost(TNode *root, TEntry &entry) {
    if (!root || root->maxy <= entry.second) {
        return NULL;
    }
    TNode *left;
    if (root->key.first > entry.first) {
        left = leftmost(root->left, entry);
    } else {
        left = NULL;
    }
    if (left) {
        return left;
    }

    if (root->key.first > entry.first && root->key.second > entry.second) {
        return root;
    }
    return leftmost(root->right, entry);
}


int main() {
    TNode *root = NULL;
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        string comm;
        int x, y;
        fin >> comm >> x >> y;
        if (comm == "add") {
            TNode *newNode = new TNode(make_pair(x, y));
            root = insert(root, newNode);
        }
        if (comm == "remove") {
            root = remove(root, make_pair(x, y));
        }
        if (comm == "find") {
            //TNode *left, *right;
            //split(root, &left, &right, make_pair(x, (int)1e9+1));
            TNode *ans = leftmost(root, make_pair(x, y));
            if (!ans) {
                fout << -1 << '\n';
            } else {
                fout << ans->key.first << ' ' << ans->key.second << '\n';
            }
            //root = merge(left, right);
        }
    }

    return 0;
}