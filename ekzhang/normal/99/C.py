import itertools

def transform(die, config):
    config = zip('012345', config)
    new = [None, None, None, None, None, None]
    for i in config:
        new[int(i[1])] = die[int(i[0])]
    return tuple(new)

def getRotations(die):
    configs = ['024135', '135024', '521430', '425031', '215043', '254103',
               '534120', '103254', '542310', '304152', '351402', '012345',
               '152304', '043215', '240513', '453201', '310542', '513240',
               '201453', '430521', '120534', '345012', '031425', '402351']
    ret = set([])
    for i in configs:
        ret.add(transform(die, i))

    return ret

def main():
    die = tuple(raw_input())
    configs = set([])
    ans = 0
    
    for i in itertools.permutations(die, 6):
        if i not in configs:
            configs |= getRotations(i)
            ans += 1

    return ans

if __name__ == '__main__':
    print main()