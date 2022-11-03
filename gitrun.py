import subprocess
import time
import random
import pprint as pp
from termcolor import colored
import os

###################################################################


def yellow(text):
    return colored(text, "yellow", attrs=["bold"])


def green(text):
    return colored(text, "green", attrs=["bold"])


def red(text):
    return colored(text, "red", attrs=["bold"])


def cyan(text):
    return colored(text, "cyan", attrs=["bold"])


###################################################################

FAST_MODE = True
MIN_WAIT_SEC = 60
MAX_WAIT_SEC = 110
WAIT_SEC = random.randint(MIN_WAIT_SEC, MAX_WAIT_SEC)
MAX_ITERATIONS = 10001

if FAST_MODE:
    MAX_FILES_TO_ADD = 29
    SLEEP_BETWEEN_ITERATIONS = 0.2#python dropbox_binger_hp_buffer.py -r 1
else:
    MAX_FILES_TO_ADD = 9
    SLEEP_BETWEEN_ITERATIONS = 9

def compact(lst):
    return list(filter(None, lst))


for i in range(1, 1 + MAX_ITERATIONS):
    if os.path.exists(".\\datetime(2022"):
        print("[{}]Running: rm .\\datetime(2022".format(i))
        p = subprocess.Popen(["rm", "\'.\\datetime(2022\'"], stdout=subprocess.PIPE)
        out, err = p.communicate()
        outlist0 = out.decode("utf-8").split("\n")
        pp.pprint(outlist0)

    print("[{}]Initializing git status1".format(i))
    p = subprocess.Popen(["git", "status"], stdout=subprocess.PIPE)
    out, err = p.communicate()
    outlist1 = out.decode("utf-8").split("\n")
    pp.pprint(outlist1)

    modifiedlist = []
    deletedlist = []
    for idx, elem in enumerate(outlist1):
        if "modified:" in elem:
            modifiedlist.append(elem.replace("modified:", ""))
        if "deleted:" in elem:
            deletedlist.append(elem.replace("deleted:", ""))
    print("[{}]modifiedlist:".format(i))
    pp.pprint(modifiedlist)
    print("[{}]deletedlist:".format(i))
    pp.pprint(deletedlist)

    trimmed = False
    for idx, elem in enumerate(outlist1):
        if "Untracked files" in elem:
            UntrackedList = outlist1[idx + 2 :]
            UntrackedList = compact(UntrackedList)
            UntrackedList = UntrackedList[:-1]
            UntrackedList = UntrackedList[:MAX_FILES_TO_ADD]
            trimmed = True
            break
    if trimmed == False:
        UntrackedList = []
    print("[{}]Untracked List:".format(i))
    pp.pprint(UntrackedList)

    print("[{}]Done git status1".format(i))
    print("=====")

    print("[{}]Initializing git add for modifiedlist".format(i))
    modifiedlist = modifiedlist[:MAX_FILES_TO_ADD]
    for idx, elem in enumerate(modifiedlist):
        try:
            elem = elem.strip()
            # if ".cpp" in elem or ".c" in elem or ".py" in elem:
            print("[{}][{}]Running git add {}".format(i, idx, elem))
            p = subprocess.Popen(["git", "add", elem], stdout=subprocess.PIPE)
            out, err = p.communicate()
            print(out.decode("utf-8").split("\n"))
        except:
            pass
    print(yellow("[{}]Done git add for modifiedlist".format(i)))
    print("=====")


    print("[{}]Initializing git add for deletedlist".format(i))
    deletedlist = deletedlist[:MAX_FILES_TO_ADD]
    for idx, elem in enumerate(deletedlist):
        try:
            elem = elem.strip()
            # if ".cpp" in elem or ".c" in elem or ".py" in elem:
            print("[{}][{}]Running git add {}".format(i, idx, elem))
            p = subprocess.Popen(["git", "add", elem], stdout=subprocess.PIPE)
            out, err = p.communicate()
            print(out.decode("utf-8").split("\n"))
        except:
            pass
    print(yellow("[{}]Done git add for deletedlist".format(i)))
    print("=====")

    print("[{}]Initializing git add for UntrackedList".format(i))
    for idx, elem in enumerate(UntrackedList):
        try:
            elem = elem.strip()
            # if ".cpp" in elem or ".c" in elem or ".py" in elem:
            print("[{}][{}]Running git add {}".format(i, idx, elem))
            p = subprocess.Popen(["git", "add", elem], stdout=subprocess.PIPE)
            out, err = p.communicate()
            print(out.decode("utf-8").split("\n"))
        except:
            pass
    print(yellow("[{}]Done git add for UntrackedList".format(i)))
    print("=====")

    print("[{}]Initializing git status2".format(i))
    p = subprocess.Popen(["git", "status"], stdout=subprocess.PIPE)
    out, err = p.communicate()
    outlist2 = out.decode("utf-8").split("\n")
    pp.pprint(outlist2)

    trimmed = False
    for idx, elem in enumerate(outlist2):
        if "Changes to be committed:" in elem:
            to_be_committed_list = outlist2[idx + 2 :]
            to_be_committed_list = compact(to_be_committed_list)
            to_be_committed_list = to_be_committed_list[:MAX_FILES_TO_ADD]
            trimmed = True
            break
    if trimmed == False:
        to_be_committed_list = []

    trimmed = False
    for idx, elem in enumerate(to_be_committed_list):
        if "Changes not staged for commit:" in elem:
            to_be_committed_list = to_be_committed_list[:idx]
            to_be_committed_list = compact(to_be_committed_list)
            to_be_committed_list = to_be_committed_list[:-1]
            to_be_committed_list = to_be_committed_list[:MAX_FILES_TO_ADD]
            break

    print("[{}]Changes to be committed List:".format(i))
    pp.pprint(to_be_committed_list)

    # finalfilelist = []
    # for elem in outlist2:
    #     if "\tnew file:" in elem:
    #         finalfilelist.append(elem)

    # print(finalfilelist)

    message_selection_list = []
    for elem in to_be_committed_list:
        try:
            message_selection_list.append(
                elem.replace("\tnew file:", "").strip().split("/")[0]
            )
        except Exception as e:
            pass

    print("[{}]Message selection List:".format(i))
    print(message_selection_list)
    if len(to_be_committed_list) == 0:
        print(cyan("[{}]Waiting {} secs....".format(i, WAIT_SEC)))
        time.sleep(WAIT_SEC)
        continue
    freq = { x: message_selection_list.count(x) for x in message_selection_list }
    print(freq)
    max_key = max(freq, key=freq.get)

    print(max_key)
    try:
        elem = max_key.strip()
        if os.path.exists("{}/downloaded".format(elem)):
            print("[{}][{}]Running git add {}/downloaded".format(i, idx, elem))
            p = subprocess.Popen(
                ["git", "add", elem + "/downloaded"], stdout=subprocess.PIPE
            )
            out, err = p.communicate()
            print(out.decode("utf-8").split("\n"))
        else:
            print("[{}][{}]{}/downloaded doesnt exist".format(i, idx, elem))

        if os.path.exists("{}/errors".format(elem)):
            print("[{}][{}]Running git add {}/errors".format(i, idx, elem))
            p = subprocess.Popen(["git", "add", elem + "/errors"], stdout=subprocess.PIPE)
            out, err = p.communicate()
            print(out.decode("utf-8").split("\n"))
        else:
            print("[{}][{}]{}/errors doesnt exist".format(i, idx, elem))
    except:
        pass

    print("[{}]Done git status2".format(i))
    print("=====")

    print("[{}]Initializing git commit".format(i))
    p = subprocess.Popen(["git", "commit", "-m", max_key], stdout=subprocess.PIPE)
    out, err = p.communicate()
    print(out.decode("utf-8").split("\n"))
    print(green("[{}]Done git commit".format(i)))
    print("=====")

    if FAST_MODE and i % 2 == 0:
        print("[{}]Initializing git push".format(i))
        p = subprocess.Popen(["git", "push"], stdout=subprocess.PIPE)
        out, err = p.communicate()
        print(out.decode("utf-8").split("\n"))
        print(green("[{}]Done git push".format(i)))
        print("=====")
    print("Sleeping for {} secs".format(SLEEP_BETWEEN_ITERATIONS))
    time.sleep(SLEEP_BETWEEN_ITERATIONS)
