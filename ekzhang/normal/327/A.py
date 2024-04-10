def main():
    N = input()
    AR = read()
    ret = -1
    beforestart = 0
    for start in xrange(len(AR)):
        prev = 0
        
        for end in xrange(start, len(AR)):
            if AR[end] == 0:
                foo = prev + 1
            else:
                foo = prev - 1

            if foo > ret:
                ret = foo

            prev = foo

    return len([x for x in AR if x == 1]) + ret



### UTILITY FUNCTIONS, END OF CODE ###

import sys

class has_constants(object):
    def __init__(self, *args):
        self.constants = args

    def __call__(self, f):
        for c in self.constants:
            exec('f.{0} = list()'.format(c))
        return f


### Credit to chaotic_iak for these functions, modified by fz0718 ###
@has_constants('str', 'str_list', 'int_list')
def read(mode=None):
    if mode is None: mode = read.int_list
    inputs = raw_input().strip()
    if mode is read.str: return inputs
    if mode is read.str_list: return inputs.split()
    if mode is read.int_list: return list(map(int, inputs.split()))

def write(s='\n'):
    if s is None: s = ''
    if hasattr(s, '__iter__'): s = ' '.join(str(x) for x in s)
    s = str(s)
    sys.stdout.write(s)

### Running main function ###
if __name__ == '__main__':
    write(main())