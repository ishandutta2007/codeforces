#!/usr/bin/env python3
import sys

n, reserved, m, *lines = sys.stdin.readlines()
n = int(n)
reserved = set(reserved.split())
m = int(m)
#assert len(lines) == m

def strip_comment(line):
    return line[:-1].split('#', maxsplit=1)[0]
lines = ' '.join(map(strip_comment, lines))

#print(repr(lines))

def is_digit(c):
    return '0' <= c <= '9'
def is_word_char(c):
    return c == '_' or c == '$' or '0' <= c <= '9' or 'A' <= c <= 'Z' or 'a' <= c <= 'z'

def digit_match(s, ind):
    assert ind < len(s)
    res = 0
    while res + ind < len(s) and is_digit(s[res + ind]):
        res += 1
    return res

def word_match(s, ind):
    assert ind < len(s)
    if is_digit(s[ind]):
        return 0
    res = 0
    while res + ind < len(s) and is_word_char(s[res + ind]):
        res += 1
    return res

def reserved_match(s, ind):
    assert ind < len(s)
    return max((len(r) for r in reserved if s.startswith(r, ind)), default=0)

def tokenize(s):
    ind = 0
    while ind < len(s):
        if s[ind] == ' ':
            ind += 1
            continue
        l = max(digit_match(s, ind), word_match(s, ind), reserved_match(s, ind))
        if l == 0:
            yield '\0' # yield a garbage character to mess up the stream
            return
        yield s[ind:ind+l]
        ind += l

def simplify_tokens(tokens):
    def lex_next(s):
        for i in range(len(s)-1, -1, -1):
            assert 'a' <= s[i] <= 'z'
            if s[i] < 'z':
                return s[:i] + chr(ord(s[i])+1) + 'a' * (len(s) - i - 1)
        return 'a' * (len(s)+1)
    converted = {}
    cur_word = ''
    for token in tokens:
        if token in reserved:
            yield token
        elif '0' <= token[0] <= '9':
            yield token
        elif token in converted:
            yield converted[token]
        else:
            cur_word = lex_next(cur_word)
            while cur_word in reserved:
                cur_word = lex_next(cur_word)

            converted[token] = cur_word
            yield cur_word

tokens = list(simplify_tokens(tokenize(lines)))
#print(tokens)

cur_tokens = []
result = []
for token in tokens:
    #assert token
    cur_tokens.append(token)
    # only have to check the last 20 tokens
    if list(tokenize(''.join(cur_tokens[-21:]))) != cur_tokens[-21:]:
        result.append(''.join(cur_tokens[:-1]))
        cur_tokens = [token]
#assert cur_tokens
if cur_tokens:
    result.append(''.join(cur_tokens))
print(' '.join(result))